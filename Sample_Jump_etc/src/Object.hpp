
#pragma once
#include "ObjectJump.hpp"


namespace common {

class Object {
public:
  Object() {
    std::ifstream load("res/character.txt");
    if (!load) own_ = Texture("res/player.png");

    std::string path;
    load >> path;
    own_ = Texture(path);
  }

  void update() {
    jump_.update();
  }

  void draw() {
    const Vec2f pos(0, -common::HEIGHT / 2);
    const Vec2f size(128, 128);
    const float jump = jump_.getJumpPower();

    drawTextureBox(pos.x(), pos.y() + jump, size.x(), size.y(),
                   0, 0, size.x(), size.y(),
                   own_, Color::white,
                   0, Vec2f::Ones(), Vec2f(size.x() / 2, 0));
  }

private:
  ObjectJump jump_;
  Texture own_;
};

}
