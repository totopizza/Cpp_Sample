
#include "common.h"
#include "ball.h"
#include <vector>


int main() {
  AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);
  Random random;
  random.setSeed(u_int(time(nullptr)));

  std::vector<cBall> ball;

  while (env.isOpen()) {

    // TIPS: 左クリックでボール追加
    if (ball.size() < BallMax &&
        env.isPushButton(Mouse::LEFT)) {
      ball.push_back(cBall(env.mousePosition(), random));
    }

    // TIPS: G キーを押してる間、重力がかかる
    if (!ball.empty() && env.isPressKey('G')) {
      for (auto& it : ball) { it.gravity(); }
    }

    // TIPS: ボールの更新
    for (auto& it : ball) { it.update(); }

    env.setupDraw();

    // TIPS: ボールの表示
    for (auto& it : ball) { it.draw(); }

    env.update();
  }
}
