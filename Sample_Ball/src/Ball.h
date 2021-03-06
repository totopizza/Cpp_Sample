
#pragma once
#include "Common.h"


namespace common {

enum {
  BallMax = 10,

  BallSize = 10,
  BallDivision = 20,
};


class Ball {
public:
  Ball(const Vec2f&, Random&);

  void gravity();

  void update();
  void draw();

private:
  Vec2f pos_;
  Vec2f speed_;
  Color color_;
};


// TIPS: 画面端の情報
class Edge {
public:
  float sup;   // 最小値
  float inf;   // 最大値

  Edge(const float s, const float i) : sup(s), inf(i) {}
};

}
