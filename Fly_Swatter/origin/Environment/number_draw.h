
#pragma once
#include "../common.h"
#include "../src/lib/font.hpp"
#include <sstream>


class cNumber {
  Font text_;

public:
  cNumber();

  void draw(const int val, const Vec2f& pos);
};
