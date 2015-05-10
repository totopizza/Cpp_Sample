
#include "../FrameWork/resource.h"
#include "../FrameWork/scene_manager.h"
#include "exec_main.h"

using namespace resource;


cExecMain::cExecMain() :
m_angle(0.0f) {

  const SpriteInfo table = {
    SpriteID::All_Sprite,
    "res/player.png",
    Color::white,
  };

  res::get()->spriteAppend(table);
}


void cExecMain::update() {
  // do not something.
}


void cExecMain::draw() {
  const Vec2f pos(0, HEIGHT / 2 - 20);
  const Vec2f size(128, 128);

  const float r = (M_PI / 6) * std::sin(m_angle);
  m_angle += 0.05f;

  drawLine(pos.x(), pos.y(),
           pos.x(), pos.y() - size.y() * 2.5f,
           4, Color::white,
           r, Vec2f(1, 1), Vec2f(0, 0));

  drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
                 0, 0, size.x(), size.y(),
                 *res::get()->sprite(SpriteID::All_Sprite),
                 Color::white,
                 r, Vec2f(1, 1),
                 Vec2f(size.x() / 2, size.y() * 3));
}


SceneState cExecMain::getScene() const {
  return SceneState::Title;
}


std::shared_ptr<cScene> cExecMain::nextScene() const {
  return std::make_shared<cExecMain>();
}


bool cExecMain::sceneFinish() const {
  return false;
}
