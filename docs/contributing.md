# 如何贡献

欢迎参与到 XMUM XCPC Wiki 的建设中来。

项目地址：[https://github.com/Xiamen-University-Malaysia/xcpc-wiki](https://github.com/Xiamen-University-Malaysia/xcpc-wiki)

可在 Wiki 页面右上角打开本项目。

本项目已经授予[厦门大学马来西亚分校算法竞赛兴趣小组](https://github.com/Xiamen-University-Malaysia/XMUM_ICPC_CCPC)成员直接读写权限，旨在通过搭建一个代码与知识库来分享算法竞赛相关内容，积累竞赛经验。

## 参与方式

### 在 GitHub 中直接编辑文档

在对应的文件页面，点击右上角的小铅笔按钮，即可直接在浏览器中修改，修改完成后填写 commit 信息提交。

### 将项目 `git clone` 到本地

推荐使用 SSH 协议：

```bash
git clone git@github.com:Xiamen-University-Malaysia/xcpc-wiki.git
```

注意：需要先在 GitHub 上设置 SSH Key，具体步骤可以参考 GitHub 官方文档：[Connecting to GitHub with SSH](https://docs.github.com/en/authentication/connecting-to-github-with-ssh)。

或者使用 HTTPS 协议：

```bash
git clone https://github.com/Xiamen-University-Malaysia/xcpc-wiki.git
```

克隆到本地后，使用文本编辑器进行编辑。修改完成后，参考下方的 [`命名规范`](#_3) 和 [`提交 commit 规范`](#commit) 进行操作。如果有新增专栏或、增文章或更改导航、更改左侧目录，需要修改 [`mkdocs.yml`](../mkdocs.yml) 文件。

推送到远程仓库前，建议在本地预览修改效果。预览前确保安装 MkDocs 及其相关依赖：

```bash
pip install -r requirements.txt
```

安装完成后，在项目的根目录下运行以下命令启动本地服务器：

```bash
mkdocs serve
```

访问终端中输出的本地地址，访问即可预览修改后的网站，通常为：[http://127.0.0.1:8000/](http://127.0.0.1:8000/)

最后通过 `git push` 推送到 GitHub 远程仓库：

```bash
git add .
git commit -m "Add P1001 solution"
git push origin main
```

或使用 GUI 工具进行提交和推送。

## 命名规范

主要命名规范遵循：

`分类（对应的文件夹）/日期-标题-作者.md`

针对每个分类：

- 题解：`solution/2024-06-01-题号-题目-作者.md`

    主要记录题解的思路和代码实现，要求清晰易懂，注释充分，格式规范。

- 比赛记录：`contest/2024-06-01-比赛名称-作者.md`

    主要记录比赛题目列表、赛时解题情况、赛后总结等信息。

- 笔记：`note/2024-06-01-主题-作者.md`

    主要记录算法、数据结构、技巧等方面的知识点，要求条理清晰，内容翔实。

- 模板：`template/2024-06-01-主题-作者.md`

    主要记录算法、数据结构、技巧等方面的知识点，需要条理清晰、内容翔实。

- 出题想法：`idea/2024-06-01-想法-作者.md`

    主要记录出题人或参与者的想法，可能不完整或未经验证。

- 资源：`resource/2024-06-01-主题.md`

    主要汇总外部资源链接、参考资料等，便于查阅和学习。

- 碎碎念：`memo/2024-06-01-内容-作者.md`

    主要记录一些零碎的想法、感受、经历等内容。

- 杂项：`misc/2024-06-01-主题-作者.md`

    主要记录一些不属于以上分类的内容。

## 提交 commit 规范

提交 commit 前确保代码或文档已经过测试和验证，能够正常运行。

关于 commit message 的规范，请使用以下格式：

- Add: 添加新内容

    Add P1001 solution

- Update: 更新现有内容

    Update index.md file

- Fix: 修复错误

    Fix P1001 solution

- Refactor: 重构代码或文档

    Refactor code structure

- Format: 调整代码或文档格式

    Format code style

- Remove: 删除内容

    Remove unused code

- MkDocs: 与 MkDocs 配置相关的更改

    MkDocs update navigation structure
