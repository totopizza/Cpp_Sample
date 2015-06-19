
/* ショットを発射するサンプルプログラム */
// . enum         列挙体
// . class        クラス
// . std::list<>  コンテナ (list)

#include "shot.hpp"
#include <list>
#include <iostream>


int main() {
  AppEnv env(WIDTH, HEIGHT, false, true);

  bool escape = false;
  std::list<cShot> shot;

  // メインループ
  while (env.isOpen() && !escape) {
    escape = env.isPushKey(ESCAPE);

    // ショット発射
    if (env.isPushButton(Mouse::LEFT)) {
      shot.push_back(cShot());
    }

    auto itr = shot.begin();
    while (itr != shot.end()) {

      // ショットの更新
      itr->update();

      // 画面外まで進んだショットがあれば削除
      itr->destroy() ? itr = shot.erase(itr) : ++itr;
    }

    // 描画
    env.begin();
    for (auto& it : shot) { it.draw(); }
    env.end();

    // ショットの数をコンソールに表示
    // XXX: GameTemplate 専用の機能
    DOUT << "shot = " << shot.size() << std::endl;
  }
}
