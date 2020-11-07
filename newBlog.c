#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char my_pop_back(char *str)
{
    const int len = strlen(str);
    if( len == 0 ) {
        return '\0';      // str が空文字列の場合は、'\0' を返す
    } else {
        char c = str[len-1];     // 末尾文字を c に代入
        str[len-1] = '\0';       // 終端記号のヌル文字を次の位置に書き込む
        return c;                      // 末尾文字を返す
    }
}

int main(int argc, char *argv[]){
  if(argc != 2){
    printf("Usage: newb <filename>\n");
    exit(1);
  }
  if(strlen(argv[1]) >= 256){
    printf("The maximum number of characters in a file name is 255.");
    exit(1);
  }
  //ファイルを開いてHTMLファイル作成
  FILE *fp;
  char fileName[256];
  strcpy(fileName,argv[1]);
  char html[2048];
  /*
  printf("whats new logs name?:");
  fgets(fileName, 256, stdin);
  my_pop_back(fileName);
  */
  fp = fopen("./blog/blogTmp.html", "r");
  if(fp == NULL){
    printf("htmlTmpファイルが読み込めませんでした");
    return -1;
  }
  char b[256];
  while((fgets(b,256,fp)) != NULL){
    if(strstr(b, "axios.get('/portfolio/blog/')")){
      printf("%s\n",fileName);
      sprintf(b,"      axios.get('/portfolio/blog/%s.md')\n",fileName);
    }
    strcat(html,b);
  }
  fclose(fp);
  //printf("%s",html);
  char newFilePathHtml[256];
  char newFilePathMd[256];

  sprintf(newFilePathHtml, "./blog/%s.html",fileName );
  sprintf(newFilePathMd, "./blog/%s.md",fileName );

  fp = fopen(newFilePathHtml, "r");
  if(fp != NULL){
    printf("Can I overwrite the file?[y/n]\n");
    char ans;
    scanf("%c",&ans);
    if(ans == 'n')return -1;
  }

  fp = fopen(newFilePathHtml, "w");
  fputs(html, fp);
  fclose(fp);

  fp = fopen(newFilePathMd, "w");
  fclose(fp);
  //ファイルを新しく
}
