
#include "../FrameWork/resource.h"
#include "../FrameWork/gadget.h"
#include "../FrameWork/scene_manager.h"
#include "result.h"


cResult::cResult() : m_blink(0) {

  res::get()->deleteSprite();
  gadget::draw()->font()->size(fontSize::MEDIUM);
}


void cResult::update() {
  if (env::get()->isPushButton(Mouse::LEFT)) {
    m_is_finish = true;
  }

  ++m_blink;
}


void cResult::draw() {
  Font& font = *gadget::draw()->font();

  {
    const std::string LOGO = "Game Over";
    const float POS_X = -font.drawSize(LOGO).x() / 2;
    const float POS_Y = HEIGHT / 2 - font.drawSize(LOGO).y() * 2.5f;

    font.draw(LOGO, Vec2f(POS_X, POS_Y), Color::white);
  }

  {
    const std::string BUTTON = "Click To Title";
    const float POS_X = -font.drawSize(BUTTON).x() / 2;
    const float POS_Y = -font.drawSize(BUTTON).y() / 2;
    const short BLINK = (m_blink / BLINK_SPEED) % 2;
    const Color COLOR(1, 1, 0, BLINK);

    font.draw(BUTTON, Vec2f(POS_X, POS_Y), COLOR);
  }
}


SceneState cResult::getScene() const {
  return SceneState::RESULT;
}


std::shared_ptr<cScene> cResult::nextScene() const {
  return std::make_shared<cTitle>();
}
