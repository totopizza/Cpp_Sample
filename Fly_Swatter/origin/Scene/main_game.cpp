
#include "main_game.h"

enum {
  Fps = 60,
  GameFinishTime = Fps * 10,

  GaugeSize_W = 400,
  GaugeSize_H = 30,
};


cMain::cMain() :
size_(Vec2f(100, 100)),
game_time_(GameFinishTime) {
  text_.size(FONT_SIZE);
  rand_.setSeed(u_int(time(nullptr)));

  enemyMove();
  timeInit();

  env::score = 0;
}


bool cMain::quitGame() {
  return false;
}


bool cMain::sceneChange() {
  return game_time_ < 0;
}


void cMain::update() {
  --game_time_;

  if (!enemy.hit_) { --enemy.move_time_; }
  if (enemy.hit_) { --enemy.hit_time_; }

  on_mouse_ = env::rectOnMouse(pos_, size_);

  if (on_mouse_ && env::leftClick() && !enemy.hit_) {
    enemy.hit_ = true;
    ++env::score;
    env::sePlay();
  }

  if (enemy.move_time_ < 0 || enemy.hit_time_ < 0) {
    enemyMove();
    timeInit();
  }
}


void cMain::timeInit() {
  enemy.hit_ = false;
  enemy.move_time_ = Fps * 2;
  enemy.hit_time_ = Fps / 2;
}


void cMain::enemyMove() {
  const float x_range_left = -WIDTH / 2;
  const float x_range_right = WIDTH / 2 - size_.x();
  const float y_range_bottom = -HEIGHT / 2;
  const float y_range_top = HEIGHT / 2 - size_.y();

  pos_.x() = rand_.fromFirstToLast(x_range_left, x_range_right);
  pos_.y() = rand_.fromFirstToLast(y_range_bottom, y_range_top);
}


void cMain::draw() {
  disp_logo();
  disp_enemy();
  disp_timeGauge();
  disp_score();
}


void cMain::disp_logo() {
  const std::string logo = "Fight! ";
  const Color orange = Color(1, 0.5f, 0);
  Vec2f pos;

  pos = -text_.drawSize(logo) / 2;
  text_.draw(logo, pos, orange);
}


void cMain::disp_enemy() {
  on_mouse_ = env::rectOnMouse(pos_, size_);

  const Color color = on_mouse_ ?
    Color(1, 0, 0) : Color(1, 1, 1);

  slight_ = Vec2f(0, 0);

  if (enemy.hit_) {
    slight_.x() = rand_.fromFirstToLast(-3.0f, 3.0f);
    slight_.y() = rand_.fromFirstToLast(-3.0f, 3.0f);
  }

  drawFillBox(pos_.x() + slight_.x(), pos_.y() + slight_.y(),
              size_.x(), size_.y(), color);
}


void cMain::disp_timeGauge() {
  const float gauge_w = float(game_time_) / GameFinishTime;
  const Color color =
    gauge_w > 0.5f ? Color(0, 1, 0) :
    gauge_w > 0.25f ? Color(1, 1, 0) :
    Color(1, 0, 0);

  drawFillBox(-GaugeSize_W / 2, HEIGHT / 2 - GaugeSize_H * 2,
              GaugeSize_W * gauge_w, GaugeSize_H, color);
}


void cMain::disp_score() {
  const Vec2f score_pos = Vec2f(-WIDTH / 2 + 20, -HEIGHT / 2 + 15);
  num_.draw(env::score, score_pos);
}
