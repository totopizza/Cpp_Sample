
#pragma once
#include "Common.hpp"


class GamePlayer {
public:
  GamePlayer() : angle_(0.0f) {
    texture_ = Texture("res/player.png");
  }

  void update() {
    angle_ += 0.05f;
  }

  void draw() {
    const Vec2f pos(0, common::HEIGHT / 2 - 20);
    const float size = 128;
    const float rad = (M_PI / 6) * std::sin(angle_);

    common::App::get().begin();

    drawLine(pos.x(), pos.y(),
             pos.x(), pos.y() - size * 2.5f,
             4, Color::white,
             rad, Vec2f::Ones(), Vec2f::Zero());

    drawTextureBox(pos.x(), pos.y(), size, size,
                   0, 0, size, size,
                   texture_, Color::white,
                   rad, Vec2f::Ones(),
                   Vec2f(size / 2, size * 3));

    common::App::get().end();
  }

  bool isRunning() {
    using namespace common;
    return App::get().isOpen() && !App::get().isPushKey(ESCAPE);
  }

private:
  Texture texture_;
  float angle_;
};
