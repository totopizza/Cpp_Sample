
#pragma once
#include "SceneBase.hpp"


namespace common {

class Title : public SceneBase {
public:
  Title() :
    SceneBase(SceneName::Title, SceneName::MainGame),
    is_click_(false),
    blink_(0),
    angle_(0.0f) {

    common::Score::get().countReset();
    font_.size(common::FontSize);
    effectSetup(effect_, "res/title.wav", 0.3f);
    effectSetup(call_, "res/start.wav", 0.3f);
    textureSetup(back_ground_, "res/title_bg.png");

    effect_.play();
  }

  void update() {
    timeUpdate();
    angleUpdate();
    blinkUpdate();
    finishScene();

    if (!is_click_ && common::App::get().isPushButton(LEFT)) {
      effect_.stop();
      call_.play();
      time_ = 0;
      angle_ = 0.0f;
      is_click_ = true;
    }
  }

  void draw() {
    drawBackGround();

    Vec2f pos;

    const std::string logo("はえたたき ");
    pos = -font_.drawSize(logo) / 2;
    pos.y() += HEIGHT / 4;
    font_.draw(logo, pos, Color::white);

    const std::string start("左クリックで開始 ");
    pos = -font_.drawSize(start) / 2;
    pos.y() += std::abs(std::sin(angle_)) * 15 - FontSize;
    font_.draw(start, pos, Color(1, 1, 1, 1 - blink_));

    Score::get().drawRankingScore();
  }

private:
  Media call_;

  bool is_click_;
  float angle_;
  short blink_;

  void angleUpdate() {
    if (is_click_) return;
    angle_ += 0.1f;
  }

  void blinkUpdate() {
    if (!is_click_) return;
    blink_ = (time_ / 2) % 2;
  }

  void finishScene() {
    if (!is_click_ || (time_ + 1) < common::Fps) return;
    is_finish_ = true;
  }
};

}
