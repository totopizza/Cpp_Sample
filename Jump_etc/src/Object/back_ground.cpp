
#include "../FrameWork/environment.h"
#include "back_ground.h"


cBackGround::cBackGround() :
m_alpha_mode(false),
m_alpha(1.0f),
m_fade_speed(-0.025f) {
}


void cBackGround::update() {
  if (m_alpha_mode) { alphaPlaying(); }

  if (env::get()->isPushKey(JUMP) && !m_alpha_mode) {
    m_alpha_mode = true;
  }
}


void cBackGround::draw() {
  using namespace resource;

  drawBG(SpriteID::BackGround_1);
  drawBG(SpriteID::BackGround_2);
}


void cBackGround::alphaPlaying() {
  m_alpha += m_fade_speed;

  if (m_alpha < 0.0f) {
    m_alpha = 0.0f;
    alphaTypeChange();
  }

  if (m_alpha > 1.0f) {
    m_alpha = 1.0f;
    alphaTypeChange();
  }
}


void cBackGround::alphaTypeChange() {
  m_fade_speed *= -1;
  m_alpha_mode = false;
}


void cBackGround::drawBG(const resource::SpriteID id) {
  const Vec2f DrawSize(WIDTH * 0.9f, HEIGHT * 0.9f);
  const Vec2f CutSize(256, 256);
  const Color SpriteColor(1, 1, 1, getAlpha(id));

  for (int line = 0; line < CutSize.y(); ++line) {
    const float angle = line * 0.01f + m_alpha;
    const float theta = std::sin(angle * M_PI);
    const float r = theta * (DrawSize.x() / 4 * (1 - getAlpha(id)));
    const float draw_h = DrawSize.y() / CutSize.y();
    const float pos_y = -DrawSize.y() / 2 + line * draw_h;

    drawTextureBox(-DrawSize.x() / 2 + r, pos_y,
                   DrawSize.x(), draw_h,
                   0, CutSize.y() - line, CutSize.x(), -1,
                   *res::get()->sprite(id), SpriteColor);
  }
}


float cBackGround::getAlpha(const resource::SpriteID id) {
  using namespace resource;

  return id == SpriteID::BackGround_1
    ? m_alpha
    : 1 - m_alpha;
}
