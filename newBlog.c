#include <stdio.h>
#include <string.h>

int main(){
  FILE *fp;
  char fileName[256];
  char html[2048];
  printf("whats new logs name?:");
  fgets(html, 256, stdin);
  fp = fopen("./blog/blogTmp.html", "r");
  if(fp == NULL){
    printf("htmlTmpファイルが読み込めませんでした");
    return -1;
  }
  char *b;
  while((fgets(b,256,fp)) != NULL){
    if(!strcmp(b, "      axios.get('/portfolio/blog/')")){
      sprintf(b,"%s%s%s","      axios.get('/portfolio/blog/",fileName,"')");
    }
    strcat(html,b);
  }
  fclose(fp);
  printf("%s",html);
  _getch();
}
