
#pragma once
#include "Common.hpp"


namespace common {

class ObjectJump {
public:
  ObjectJump() : jump_power_(0.0f), jump_velocity_(0.0f) {}

  void update() {
    actionUpdate();
    if (!isJumping() && App::get().isPushKey(JUMP)) { jump_velocity_ += JumpPower; }
  }

  const float getJumpPower() const { return jump_power_; }

private:
  enum Parameter { JumpPower = 20, };

  float jump_power_;
  float jump_velocity_;

  inline const float getGravity() const { return -1.0f; }

  const bool isJumping() const { return jump_power_ > 0.0f; }

  void actionUpdate() {
    jump_power_ += jump_velocity_;

    jump_power_ <= 0.0f
      ? jump_power_ = 0.0f
      : jump_velocity_ += getGravity();

    if (!isJumping()) jump_velocity_ = 0.0f;
  }
};

}
