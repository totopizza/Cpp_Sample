
#pragma once
#include "Common.hpp"
#include "Ranking.h"


namespace common {

enum KeyBind {
  ESCAPE = GLFW_KEY_ESCAPE,
};


class App {
public:
  static AppEnv& get() {
    static AppEnv s_env(WIDTH, HEIGHT, false, false);
    return s_env;
  }

  App() = default;

  void update() {
    rank_.update();
  }

  void draw() {
    get().begin();
    rank_.draw();
    get().end();
  }

  const inline bool isPushEscape() const {
    return get().isPushKey(ESCAPE);
  }

private:
  Ranking rank_;
};

}
