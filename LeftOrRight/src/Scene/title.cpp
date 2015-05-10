
#include "../FrameWork/resource.h"
#include "../FrameWork/gadget.h"
#include "../FrameWork/scene_manager.h"
#include "title.h"


cTitle::cTitle() : m_blink(0) {

  res::get()->deleteSprite();
  gadget::draw()->font()->size(fontSize::MEDIUM);
}


void cTitle::update() {
  if (env::get()->isPushButton(Mouse::LEFT)) {
    m_is_finish = true;
  }

  ++m_blink;
}


void cTitle::draw() {
  Font& font = *gadget::draw()->font();

  {
    const std::string LOGO = "Left or Right";
    const float POS_X = -font.drawSize(LOGO).x() / 2;
    const float POS_Y = HEIGHT / 2 - font.drawSize(LOGO).y() * 2;

    font.draw(LOGO, Vec2f(POS_X, POS_Y), Color::white);
  }

  {
    const std::string START = "Click Start !";
    const float POS_X = -font.drawSize(START).x() / 2;
    const float POS_Y = -font.drawSize(START).y() / 2;
    const short BLINK = (m_blink / BLINK_SPEED) % 2;
    const Color COLOR(1, 1, 0, BLINK);

    font.draw(START, Vec2f(POS_X, POS_Y), COLOR);
  }
}


SceneState cTitle::getScene() const {
  return SceneState::TITLE;
}


std::shared_ptr<cScene> cTitle::nextScene() const {
  return std::make_shared<cMainGame>();
}
