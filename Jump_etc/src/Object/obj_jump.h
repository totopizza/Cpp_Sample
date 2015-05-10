
#pragma once
#include "obj_interface.h"


class cObjectJump : public cObjectInterface {

  enum Parameter {
    JumpPower = 20,
  };

  float m_jump_power;
  float m_jump_velocity;

  inline const float getGravity() const {
    return -1.0f;
  }

  void actionUpdate();

public:

  cObjectJump(cObject*);

  void update();

  bool isJumping() const;
  float getJumpPower() const;
  float getJumpVelocity() const;
};
