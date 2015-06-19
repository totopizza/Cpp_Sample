
/* . ジャンプするオブジェクト
 * . 背景のアニメーション
 * . 外部データ読み込み
 * の、サンプルプログラム
 */
// . enum       列挙体
// . namespace  名前空間
// . class      クラス

#include "GamePlayer.hpp"

using namespace common;


int main() {
  App::get();
  GamePlayer game;

  while (game.isOpen()) {
    game.update();
    game.draw();
  }
}
