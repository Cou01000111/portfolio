'use strict';
function reaTextFile(){
  var rawFile = new XMLHttpRequest();
  var fileName = "./pass.txt"
  var allText;
  rawFile.open("GET", fileName, false);
  rawFile.onreadystatechange = () => {
    if(rawFile.readyState === 4){
      if(rawFile.status === 200 || rawFile.status == 0){
        allText = rawFile.responseText;
        return allText;
      }
    }
  }
}

var pass = document.getElementById("password").value;
if(pass == reaTextFile()){
  axios.get('/portfolio/blog/daigaku.md')
    .then(response => {
      document.getElementById('markdownArea').innerHTML = marked(response.data)
      console.log(response.data)
    });
}else{
  alert('パスワードが違います');
}
