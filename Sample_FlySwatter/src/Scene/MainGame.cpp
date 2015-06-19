
#include "MainGame.h"

using namespace common;


Main::Main() :
SceneBase(SceneName::MainGame, SceneName::Result),
size_(Vec2f(100, 100)),
game_time_(GameFinishTime) {
  font_.size(FontSize);
  effectSetup(effect_, "res/hit.wav", 0.3f);
  textureSetup(back_ground_, "res/game_bg.png");
  textureSetup(enemy_, "res/miku.png");
  textureSetup(enemy_hit_, "res/miku_hit.png");
  rand_.setSeed(u_int(time(nullptr)));

  enemyInit();
  enemyMove();

  Score::get().countReset();
}


void Main::update() {
  --game_time_;
  !hit_ ? --move_time_ : --hit_time_;

  on_mouse_ = isOnRect(pos_, size_);

  if (on_mouse_ && !hit_ && App::get().isPushButton(Mouse::LEFT)) {
    hit_ = true;
    Score::get().countUp();
    effect_.play();
  }

  if (move_time_ < 0 || hit_time_ < 0) {
    enemyInit();
    enemyMove();
  }

  if (game_time_ < 0) is_finish_ = true;
}


void Main::draw() {
  dispBackGround();
  dispLogo();
  dispEnemy();
  dispTimeGauge();
  dispScore();
}


void Main::enemyInit() {
  hit_ = false;
  move_time_ = Fps * 2;
  hit_time_  = Fps / 2;
}


void Main::enemyMove() {
  const float x_sup = -WIDTH / 2;
  const float x_inf = WIDTH / 2 - size_.x();
  const float y_sup = -HEIGHT / 2;
  const float y_inf = HEIGHT / 2 - size_.y();

  pos_.x() = rand_(x_sup, x_inf);
  pos_.y() = rand_(y_sup, y_inf);
}


void Main::dispBackGround() {
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
                 0, 0, 512, 512,
                 back_ground_);
}


void Main::dispLogo() {
  const std::string logo = "Fight! ";
  const auto pos = -font_.drawSize(logo) / 2;
  font_.draw(logo, pos, Color::cyan);
}


void Main::dispEnemy() {
  Color color = isOnRect(pos_, size_) ? Color::red : Color::white;

  offset_ = Vec2f::Zero();

  if (hit_) {
    offset_.x() = rand_(-3.0f, 3.0f);
    offset_.y() = rand_(-3.0f, 3.0f);
    color = Color::white;
  }

  const auto pos = pos_ + offset_;
  const auto& sprite = hit_ ? enemy_hit_ : enemy_;

  drawFillBox(pos.x(), pos.y(), size_.x(), size_.y(), color);

  drawTextureBox(pos.x(), pos.y(), size_.x(), size_.y(),
                 0, 0, 256, 256, sprite);
}


void Main::dispTimeGauge() {
  const float gauge_w = game_time_ / static_cast<float>(GameFinishTime);
  const Color color =
    gauge_w > 0.50f ? Color::lime :
    gauge_w > 0.25f ? Color::yellow :
    Color::red;

  drawFillBox(-GaugeSize_W / 2, HEIGHT / 2 - GaugeSize_H * 2,
              GaugeSize_W * gauge_w, GaugeSize_H, color);
}


void Main::dispScore() {
  Score::get().drawCurrentScore();
}
