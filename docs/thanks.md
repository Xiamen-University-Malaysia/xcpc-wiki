# 感谢

感谢所有参与本项目的选手：

<div id="contributors" style="display: flex; flex-wrap: wrap; gap: 8px;"></div>
<script>
fetch('https://api.github.com/repos/Xiamen-University-Malaysia/xcpc-wiki/contributors')
  .then(response => response.json())
  .then(data => {
    const container = document.getElementById('contributors');
    data.forEach(user => {
      const a = document.createElement('a');
      a.href = user.html_url;
      a.target = '_blank';
      a.title = user.login;

      const img = document.createElement('img');
      img.src = user.avatar_url;
      img.alt = user.login;
      img.style.width = '40px';
      img.style.height = '40px';
      img.style.borderRadius = '50%';
      img.style.border = '1px solid rgba(128, 128, 128, 0.3)';

      a.appendChild(img);
      container.appendChild(a);
    });
  });
</script>
