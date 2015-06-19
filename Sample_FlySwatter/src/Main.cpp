
/* はえたたき（もぐらたたき系ゲームのサンプルプログラム） */
// . enum               列挙体
// . struct             構造体
// . class              クラス
// . std::shared_ptr<>  スマートポインタ
// . std::vector<>      コンテナ (vector)
// . std::map<>         コンテナ (map)

#include "Common.hpp"
#include "Scene/SceneManager.hpp"

using namespace common;


int main() {
  App::get();
  Score::get().scoreLoad();
  SceneManager manager;

  while (manager.isOpen()) {
    manager.update();
    manager.draw();
  }
}


// マウスの当たり判定
const bool common::isOnRect(const Vec2f& pos, const Vec2f& size) {
  const auto& m_pos = App::get().mousePosition();

  const auto x_sup = m_pos.x() > pos.x();
  const auto x_inf = m_pos.x() < pos.x() + size.x();
  const auto y_sup = m_pos.y() > pos.y();
  const auto y_inf = m_pos.y() < pos.y() + size.y();

  return x_sup && x_inf && y_sup && y_inf;
}
