# いろんなことをまとめるためにブログっぽいものを描き始めた話

## 目的

本当にまとめるためだけに作った

ほんとうにそれだけ
ここからはこだわった点とか言っていくよ

## こだわった点

### ライブラリ感のあるスタイルシート
f12を押して、ソースを見てもらえばわかると思うんですけど、cssを完全にheader,fotterに分けて記述していてかつ、それぞれ導入しても別の要素に影響を与えないような書き方をしています

なのでこのサイトで使ったheader.cssやfooter.css,content.cssなどは別のサイトで流用することができます（多分）

### ブログの記事を楽に追加できるシステム
ブログのテンプレートはある程度出来ているので、そのままリンクとかを書き換えればいい状況です。

なので、それのテンプレートをコピペする作業を自動化するためにCでそれっぽいものを書き、ローカルのコマンドプロンプトで```newb <filename>```を入力すればあとは生成されたファイルにマークダウンを書き込めば問題ない状況になっています

ちなみにCで書いている理由はどうせ自分しか使わない上、自分が使える技術では実装するのに一番実装が楽だったという理由しかありません（つまり手抜きです）