
/* ランキング表示のサンプルプログラム */
// . enum           列挙体
// . typedef        別名宣言
// . namespace      名前空間
// . std::ifstream  ファイル読み込み
// . class          クラス
// . std::list<>    コンテナ (list)
// . std::map<>     コンテナ (map)
// . []() {}        ラムダ式

#include "App.hpp"


int main() {
  auto& app = common::App::get();
  common::App env;

  while (app.isOpen() && !env.isPushEscape()) {
    env.update();
    env.draw();
  }
}
