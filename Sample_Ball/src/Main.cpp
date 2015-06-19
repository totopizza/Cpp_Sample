
/* 画面内を跳ね回るボールのサンプルプログラム */
// . enum           列挙体
// . class          クラス
// . std::vector<>  コンテナ (vector)

#include "Common.h"
#include "Ball.h"
#include <vector>


int main() {
  using namespace common;
  AppEnv env(common::WIDTH, common::HEIGHT, false, false);

  Random random;
  random.setSeed(u_int(time(nullptr)));

  std::vector<Ball> ball;

  while (env.isOpen()) {

    // 左クリックでボール追加
    // TIPS: ボールの数がまだ最大じゃない時だけ追加
    if (ball.size() < BallMax && env.isPushButton(Mouse::LEFT)) {
      ball.push_back(Ball(env.mousePosition(), random));
    }

    // 右クリックでボール消去
    if (env.isPushButton(Mouse::RIGHT)) { ball.clear(); }

    // TIPS: G キーを押してる間、重力がかかる
    if (!ball.empty() && env.isPressKey('G')) {
      for (auto& it : ball) { it.gravity(); }
    }

    // TIPS: ボールの更新
    for (auto& it : ball) { it.update(); }

    // TIPS: ボールの表示
    env.begin();
    for (auto& it : ball) { it.draw(); }
    env.end();
  }
}
