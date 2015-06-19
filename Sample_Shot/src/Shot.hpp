
#pragma once
#include "lib/defines.hpp"
#include "lib/appEnv.hpp"


enum WindowSize {
  WIDTH = 512,
  HEIGHT = 512,
};


enum KeyBind {
  ESCAPE = GLFW_KEY_ESCAPE,
};


enum GameInfo {
  DefaultPos_X = 0,
  DefaultPos_Y = -HEIGHT / 4,

  DeadPos_Y = HEIGHT / 2,

  ShotSize = 10,
  ShotDivision = 20,
  ShotSpeed_Y = 10,
};


class cShot {
public:
  cShot() : pos_(Vec2f(DefaultPos_X, DefaultPos_Y)) {}

  void update() {
    pos_.y() += ShotSpeed_Y;
  }

  void draw() {
    drawFillCircle(pos_.x(), pos_.y(),
                   ShotSize, ShotSize,
                   ShotDivision, Color::white);
  }

  const bool destroy() const { return pos_.y() > DeadPos_Y; }

private:
  Vec2f pos_;
};
