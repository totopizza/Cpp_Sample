
#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include <fstream>


namespace common {

enum WindowSize {
  WIDTH = 512,
  HEIGHT = 512,
};


enum KeyBind {
  ESCAPE = GLFW_KEY_ESCAPE,
  JUMP   = GLFW_KEY_SPACE,
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
