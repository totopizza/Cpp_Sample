
#pragma once
#include "SceneBase.hpp"


class Result : public SceneBase {
public:
  Result() : SceneBase(SceneName::Result, SceneName::Title) {
    font_.size(common::MEDIUM);
  }

  void update() {
    using namespace common;
    is_finish_ = App::get().isPushButton(Mouse::LEFT);

    blink_ = (time_ / common::BlinkSpeed) % 2;
    ++time_;
    if (time_ < common::Fps) return;
    time_ = 0;
  }

  void draw() {
    const std::string logo("Game Over");
    const auto l_pos = -font_.drawSize(logo) / 2 + Vec2f(0, 60);
    font_.draw(logo, l_pos, Color::white);

    const std::string action("Click To Title");
    const auto a_pos = -font_.drawSize(action) / 2 + Vec2f(0, -60);
    const Color color(1, 1, 0, blink_);
    font_.draw(action, a_pos, color);

    gadget::get().scoreDraw();
  }
};
