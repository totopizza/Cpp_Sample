## サンプルの再現プログラム一覧
- 随時更新の予定

### .gitignore 編集手順
> コマンド
- echo ***** >> .gitignore

> *.sdf
- 拡張子が一致するすべてのファイルの push を回避

> lib/
- 名前の一致するフォルダの push を回避
- 大文字小文字を区別するようなので、
  [Ll]ib/ のようにすると、頭文字に大文字小文字のどちらを使っても push を回避するようになる
