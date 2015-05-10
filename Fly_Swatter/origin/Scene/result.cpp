
#include "result.h"


enum {
  Fps = 60,
};


cResult::cResult() {
  text_.size(FONT_SIZE);
  stop_time_ = Fps;
}


bool cResult::quitGame() {
  return env::rightClick();
}


bool cResult::sceneChange() {
  if (stop_time_ > 0) { return false; }
  return env::leftClick();
}


void cResult::update() {
  if (stop_time_ > 0) { --stop_time_; }
}


void cResult::draw() {
  const std::string logo = "リザルト ";
  const Color white = Color(1, 1, 1);
  Vec2f pos;

  pos = -text_.drawSize(logo) / 2;
  pos.y() += HEIGHT / 4;
  text_.draw(logo, pos, white);

  const std::string left = "左クリックでタイトル ";

  pos = -text_.drawSize(left) / 2;
  pos.y() -= HEIGHT / 6;
  text_.draw(left, pos, white);

  const std::string right = "右クリックで終了 ";

  pos = -text_.drawSize(right) / 2;
  pos.y() -= HEIGHT / 4;
  text_.draw(right, pos, white);

  disp_score();
}


void cResult::disp_score() {
  const Vec2f score_pos = Vec2f(-WIDTH / 2 + 20, -HEIGHT / 2 + 15);
  num_.draw(env::score, score_pos);
}
