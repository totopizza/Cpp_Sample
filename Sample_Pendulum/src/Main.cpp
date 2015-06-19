
/* 振り子のサンプルプログラム */
// . enum   列挙体
// . class  クラス

#include "GamePlayer.hpp"


int main() {
  common::App::get();
  GamePlayer game;

  while (game.isRunning()) {
    game.update();
    game.draw();
  }
}
