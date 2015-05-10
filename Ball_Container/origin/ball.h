
#pragma once
#include "common.h"


enum {
  BallMax = 10,
};


class cBall {
  Vec2f pos_;
  Vec2f speed_;
  Color color_;

public:
  cBall(const Vec2f&, Random&);

  void gravity();
  
  void update();
  void draw();
};
