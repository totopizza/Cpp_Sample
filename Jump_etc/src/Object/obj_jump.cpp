
#include "../FrameWork/environment.h"
#include "object.h"
#include "obj_jump.h"


cObjectJump::cObjectJump(cObject* obj) :
cObjectInterface(obj),
m_jump_power(0.0f),
m_jump_velocity(0.0f) {
}


void cObjectJump::update() {
  actionUpdate();

  if (env::get()->isPushKey(JUMP) && !isJumping()) {
    m_jump_velocity = JumpPower;
  }
}


bool cObjectJump::isJumping() const {
  return m_jump_power > 0.0f;
}


float cObjectJump::getJumpPower() const {
  return m_jump_power;
}


float cObjectJump::getJumpVelocity() const {
  return m_jump_velocity;
}


void cObjectJump::actionUpdate() {
  m_jump_power += m_jump_velocity;

  if (m_jump_power <= 0.0f) {
    m_jump_power = 0.0f;
    return;
  }

  m_jump_velocity += getGravity();
}
