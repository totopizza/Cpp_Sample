
#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


namespace common {

enum WindowSize {
  WIDTH  = 512,
  HEIGHT = 512,

  ESCAPE = GLFW_KEY_ESCAPE,
};


class App {
public:
  static AppEnv& get() {
    static AppEnv s_env(WIDTH, HEIGHT, false, true);
    return s_env;
  }

private:
  App() = default;
};

}
