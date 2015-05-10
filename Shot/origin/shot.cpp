
#include "shot.h"

enum {
  DefaultPos_X = 0,
  DefaultPos_Y = -HEIGHT / 4,

  DeadPos_Y    = HEIGHT / 2,

  ShotSize     = 10,
  ShotDivision = 20,
  ShotSpeed_Y  = 10,
};


cShot::cShot() :
pos_(Vec2f(DefaultPos_X, DefaultPos_Y)) {
}


void cShot::update() {
  pos_.y() += ShotSpeed_Y;
}


void cShot::draw() {
  const Color white = Color(1, 1, 1);

  drawFillCircle(pos_.x(), pos_.y(),
                 ShotSize, ShotSize,
                 ShotDivision, white);
}


bool cShot::destroy() {
  return pos_.y() > DeadPos_Y;
}
