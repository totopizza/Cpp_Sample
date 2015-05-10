
#pragma once
#include "common.h"


class cShot {
  Vec2f pos_;

public:
  explicit cShot();

  void update();
  void draw();

  bool destroy();
};
