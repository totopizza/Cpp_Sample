
/* トランプゲームのサンプルプログラム */
// . enum           列挙体
// . namespace      名前空間
// . class          クラス
// . std::vector<>  コンテナ (vector)
// . std::queue<>   コンテナ (queue)

#include "GamePlayer.hpp"


int main() {
  common::App::get();
  GamePlayer game;

  while (game.isRunning()) {
    game.update();
    game.draw();
  }
}


bool common::isOnRect(const Vec2f& pos, const Vec2f& size) {
  const auto& m_pos = App::get().mousePosition();

  const auto x_sup = m_pos.x() > pos.x();
  const auto x_inf = m_pos.x() < pos.x() + size.x();
  const auto y_sup = m_pos.y() > pos.y();
  const auto y_inf = m_pos.y() < pos.y() + size.y();

  return x_sup && x_inf && y_sup && y_inf;
}
