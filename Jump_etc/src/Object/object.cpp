
#include "../FrameWork/resource.h"
#include "object.h"

using namespace resource;


cObject::cObject() {
}


void cObject::componentInit() {
  m_jump = std::make_unique<cObjectJump>(this);
}


void cObject::update() {
  m_jump->update();
}


void cObject::draw() {
  const Vec2f pos(0, -HEIGHT / 2);
  const Vec2f size(128, 128);
  const float jump = m_jump->getJumpPower();

  drawTextureBox(pos.x(), pos.y() + jump, size.x(), size.y(),
                 0, 0, size.x(), size.y(),
                 *res::get()->sprite(SpriteID::Character),
                 *res::get()->color(SpriteID::Character),
                 0, Vec2f(1, 1), Vec2f(size.x() / 2, 0));
}
