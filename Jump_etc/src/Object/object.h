
#pragma once
#include <memory>
#include <map>
#include "../common.hpp"
#include "obj_jump.h"


class cObject {

  std::unique_ptr<cObjectJump> m_jump;

public:

  cObject();

  void componentInit();

  void update();
  void draw();
};
