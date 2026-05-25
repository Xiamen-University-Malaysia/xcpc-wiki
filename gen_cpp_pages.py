import mkdocs_gen_files
from pathlib import Path
from urllib.parse import quote
from collections import defaultdict
import zipfile
import io

SCAN_DIRS = [
    Path("docs/note"),
    Path("docs/template"),
]


def build_tree(file_list, base):
    tree = defaultdict(list)
    loose = []
    for f in file_list:
        rel = f.relative_to(base)
        if len(rel.parts) == 1:
            loose.append(f)
        else:
            subdir = rel.parts[0]
            tree[subdir].append(f)
    return tree, loose


def write_tree(f, file_list, base, author_base, depth=0):
    tree, loose = build_tree(file_list, base)
    for cpp_file in loose:
        rel = cpp_file.relative_to(author_base)
        md_rel = str(rel.with_suffix(".md")).replace("\\", "/")
        f.write(f"- [{cpp_file.stem}]({md_rel})\n")
    for subdir, sub_files in sorted(tree.items()):
        heading = "#" * (depth + 2)
        f.write(f"\n{heading} {subdir}\n\n")
        write_tree(f, sub_files, base / subdir, author_base, depth + 1)


for scan_root in SCAN_DIRS:
    section = scan_root.name

    authors = defaultdict(list)
    for cpp_file in sorted(scan_root.rglob("*.cpp")):
        rel = cpp_file.relative_to(scan_root)
        if len(rel.parts) < 2:
            continue
        author = rel.parts[0]
        authors[author].append(cpp_file)

    for author, files in sorted(authors.items()):
        for cpp_file in files:
            rel = cpp_file.relative_to(scan_root)
            md_path = Path(section) / rel.with_suffix(".md")
            title = str(rel.with_suffix("")).replace("\\", "/")
            content = cpp_file.read_text(encoding="utf-8")
            cpp_filename = cpp_file.name

            download_path = Path(section) / rel
            with mkdocs_gen_files.open(download_path, "wb") as f:
                f.write(cpp_file.read_bytes())

            cpp_url = f"/{section}/" + "/".join(quote(p) for p in rel.parts)
            with mkdocs_gen_files.open(md_path, "w", encoding="utf-8") as f:
                f.write(f"# {title}\n\n")
                f.write(f'<a href="{cpp_url}" download="{cpp_filename}" class="md-button md-button--primary">')
                f.write(f"⬇ 下载 {cpp_filename}</a>\n\n")
                f.write("```cpp\n")
                f.write(content)
                if not content.endswith("\n"):
                    f.write("\n")
                f.write("```\n")

        zip_filename = f"{author}-{section}.zip"
        zip_buffer = io.BytesIO()
        with zipfile.ZipFile(zip_buffer, "w", zipfile.ZIP_DEFLATED) as zf:
            for cpp_file in files:
                rel = cpp_file.relative_to(scan_root / author)
                zf.writestr(str(rel).replace("\\", "/"), cpp_file.read_bytes())

        zip_path = Path(section) / author / zip_filename
        with mkdocs_gen_files.open(zip_path, "wb") as f:
            f.write(zip_buffer.getvalue())

        index_path = Path(section) / author / "index.md"
        with mkdocs_gen_files.open(index_path, "w", encoding="utf-8") as f:
            f.write(f"# {author}\n\n")
            f.write(f'<a href="{zip_filename}" download class="md-button md-button--primary">')
            f.write(f"⬇ 下载全部 ({zip_filename})</a>\n\n")
            write_tree(f, files, scan_root / author, scan_root / author)
