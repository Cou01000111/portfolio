#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
  //コマンドライン引数が二つ以上ついていた場合はusageを表示して終了
  if(argc != 2){
    printf("Usage: newb <filename>\n");
    exit(1);
  }
  //引数がファイル名の上限の255文字を超えていた場合はエラーを表示して終了
  if(strlen(argv[1]) >= 256){
    printf("The maximum number of characters in a file name is 255.");
    exit(1);
  }


  FILE *fp;
  //新規作成するファイル名
  char fileName[256];
  strcpy(fileName,argv[1]);
  printf("%s\n",fileName);
  //新規作成するhtmlファイルの中身
  char html[3000];

  //テンプレートファイルを読み込み
  fp = fopen("./blog/blogTmp.html", "r");
  //読み込みミスった時の処理
  if(fp == NULL){
    printf("htmlTmpファイルが読み込めませんでした");
    return -1;
  }

  //バッファのb
  char b[256] = "\0";
  //blogTmp.htmlからhtmlテンプレートを一行ずつNULLが読み込まれるまで読み込み
  while((fgets(b,256,fp)) != NULL){
    //パスが含まれているところのみ書き換え
    if(strstr(b, "axios.get('/portfolio/blog/')")){
      sprintf(b,"      axios.get('/portfolio/blog/%s.md')\n",fileName);
      //printf("1:%s\n",fileName);
    }
    strcat(html,b);
    //printf("2:%s\n",fileName);
  }
  fclose(fp);
  //printf("3:%s\n",fileName);
  //printf("%s",html);
  //新規作成するhtmlファイルのPath
  char newFilePathHtml[256];
  //新規作成するMdファイルのPath
  char newFilePathMd[256];
  //Path生成

  sprintf(newFilePathHtml, "./blog/%s.html",fileName );
  sprintf(newFilePathMd, "./blog/%s.md",fileName );
  //readonlyでファイルを開きファイルを新規作成
  fp = fopen(newFilePathHtml, "r");
  //すでに同じ名前のファイルがある場合上書き保存するか聞く
  if(fp != NULL){
    printf("Can I overwrite the file?[y/n]\n");
    char ans;
    scanf("%c",&ans);
    if(ans == 'n')return -1;
  }
  printf("create %s\ncreate%s\n",newFilePathHtml,newFilePathMd);

  //htmlファイルをもう一度開く
  fp = fopen(newFilePathHtml, "w");
  //htmlに書き込み
  fputs(html, fp);
  printf("%s\n",html);
  fclose(fp);
  //printf("create %s\n",fileName);
  //mdファイル新規作成
  fp = fopen(newFilePathMd, "w");
  fclose(fp);
  //ファイルを新しく
}
