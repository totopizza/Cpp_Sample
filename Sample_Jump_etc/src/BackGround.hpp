
#pragma once
#include "Common.hpp"


namespace common {

class BackGround {
public:
  BackGround() :
    alpha_play_(false),
    alpha_(1.0f),
    speed_(-0.025f) {

    std::ifstream load("res/bg.txt");
    if (!load) {
      bg_1_ = Texture("res/bg1.png");
      bg_2_ = Texture("res/bg2.png");
    }

    std::string path;
    load >> path;
    bg_1_ = Texture(path);
    load >> path;
    bg_2_ = Texture(path);
  }

  void update() {
    if (alpha_play_) alphaPlaying();
    if (!alpha_play_ && App::get().isPushKey(JUMP)) alpha_play_ = true;
  }

  void draw() {
    drawBG(bg_1_, alpha_);
    drawBG(bg_2_, 1 - alpha_);
  }

private:
  bool alpha_play_;
  float alpha_;
  float speed_;

  Texture bg_1_;
  Texture bg_2_;

  void alphaPlaying() {
    alpha_ += speed_;

    if (alpha_ < 0.0f) {
      alpha_ = 0.0f;
      alphaModeChange();
    }

    if (alpha_ > 1.0f) {
      alpha_ = 1.0f;
      alphaModeChange();
    }
  }

  void alphaModeChange() {
    speed_ *= -1;
    alpha_play_ = false;
  }

  void drawBG(const Texture& texture, const float alpha0) {
    const Vec2f d_size(WIDTH * 0.9f, HEIGHT * 0.9f);
    const Vec2f c_size(256, 256);
    const Color color(1, 1, 1, alpha0);

    for (int line = 0; line < c_size.y(); ++line) {
      const float angle = line * 0.01f + alpha_;
      const float theta = std::sin(angle * M_PI);
      const float offset_x = theta * (d_size.x() / 4 * (1 - alpha0));
      const float x_pos = -d_size.x() / 2 + offset_x;

      const float y_size = d_size.y() / c_size.y();
      const float y_pos = -d_size.y() / 2 + line * y_size;

      drawTextureBox(x_pos, y_pos, d_size.x(), y_size,
                     0, c_size.y() - line, c_size.x(), -1,
                     texture, color);
    }
  }
};

}
