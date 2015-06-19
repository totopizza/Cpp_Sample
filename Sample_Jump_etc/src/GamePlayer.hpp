
#pragma once
#include "Object.hpp"
#include "BackGround.hpp"


namespace common {

class GamePlayer {
public:
  GamePlayer() {}

  void update() {
    bg_.update();
    obj_.update();
  }

  void draw() {
    App::get().begin();
    bg_.draw();
    obj_.draw();
    App::get().end();
  }

  const bool isOpen() { return App::get().isOpen() && !App::get().isPushKey(ESCAPE); }

private:
  Object obj_;
  BackGround bg_;
};

}
