
#pragma once
#include "Gadget.hpp"
#include "Scene/SceneManager.hpp"


class GamePlayer {
public:
  GamePlayer() {
    common::App::get().bgColor(Color(0, 0, 0.2f));
    gadget::get();
  }

  void update() {
    manager_.update();
  }

  void draw() {
    common::App::get().begin();
    manager_.draw();
    common::App::get().end();
  }

  bool isRunning() {
    using namespace common;
    return App::get().isOpen() && !App::get().isPushKey(ESCAPE);
  }

private:
  SceneManager manager_;
};
