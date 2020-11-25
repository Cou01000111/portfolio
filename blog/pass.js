'use strict';
var pass = document.getElementById("password").value;
if(pass == 'courange0723'){
  axios.get('/portfolio/blog/daigaku.md')
    .then(response => {
      document.getElementById('markdownArea').innerHTML = marked(response.data)
      console.log(response.data)
    });
}else{
  alert('パスワードが違います');
}
