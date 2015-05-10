
#include "title.h"


cTitle::cTitle() {
  text_.size(FONT_SIZE);
}


bool cTitle::quitGame() {
  return false;
}


bool cTitle::sceneChange() {
  return false;
}


void cTitle::update() {}   // do not act.


void cTitle::draw() {
  const std::string logo = "�͂������� ";
  const Color white = Color(1, 1, 1);
  Vec2f pos;

  pos = -text_.drawSize(logo) / 2;
  text_.draw(logo, pos, white);

  const std::string start = "���N���b�N�ŊJ�n ";

  pos = -text_.drawSize(start) / 2;
  pos.y() -= 60;
  text_.draw(start, pos, white);
}
