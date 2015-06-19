
#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/font.hpp"
#include "lib/random.hpp"
#include <ctime>


namespace common {

enum WindowSize {
  WIDTH  = 512,
  HEIGHT = 512,
};


enum GameSystem {
  Fps = 60,
  FontSize = 40,
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


const bool isOnRect(const Vec2f&, const Vec2f&);

}
