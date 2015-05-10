
#include "../FrameWork/resource.h"
#include "../FrameWork/gadget.h"
#include "../FrameWork/scene_manager.h"
#include "main_game.h"


cMainGame::cMainGame() :
m_game_time(0),
m_STR("time: "),
m_POS(-WIDTH * 0.5f + 4, -HEIGHT * 0.5f + 4) {

  res::get()->deleteSprite();
  spriteInit();

  gadget::draw()->font()->size(fontSize::SMALL);
}


void cMainGame::spriteInit() {
  using namespace resource;

  const SpriteInfo table[] = {
    { SpriteID::Card, "res/card.png" },
  };

  for (auto& id : table) {
    res::get()->spriteAppend(id);
  }
}


Color cMainGame::setGaugeColor(const float per) {
  return
    per > 0.66f ? Color::lime :
    per > 0.33f ? Color::yellow :
    Color::red;
}


void cMainGame::update() {
  ++m_game_time;
  if (m_game_time < PLAY_TIME) return;

  m_is_finish = true;
}


void cMainGame::draw() {
  Font& font = *gadget::draw()->font();
  font.draw(m_STR, m_POS, Color::yellow);

  const float POS_X = m_POS.x() + font.drawSize(m_STR).x();
  const float GAUGE_W = (WIDTH * 0.5f - 10) + (POS_X * -1);
  const float PER = (PLAY_TIME - m_game_time) / float(PLAY_TIME);

  drawFillBox(POS_X, m_POS.y(),
              GAUGE_W * PER, GAUGE_H,
              setGaugeColor(PER));
}


SceneState cMainGame::getScene() const {
  return SceneState::MAIN_GAME;
}


std::shared_ptr<cScene> cMainGame::nextScene() const {
  return std::make_shared<cResult>();
}
