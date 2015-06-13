
// 2015/06/13
// コンテナとスマートポインタを使ったシューティングのサンプル

#include "GameObject.h"
#include <iostream>


int main() {
  AppEnv& env = Env::get();
  auto& list = GameObject::getObject();

  // 自機を出現させる
  list.push_back(pObject(new Player()));

  // メインループ
  while (env.isOpen()) {

    // ゲームに登場するすべてのオブジェクトを更新
    for (auto& it : list) it->update();

    // 画面外のショットを削除する
    GameObject::objectKill();

    // ゲームに登場するすべてのオブジェクトを描画
    env.begin();
    for (auto& it : list) it->draw();
    env.end();

    // コンテナにあるオブジェクトの数をコンソールに表示
    // TIPS: 西山先生のライブラリ限定の機能なので、他では使えません
    DOUT << "obj_count = " << list.size() << std::endl;
  }
}
