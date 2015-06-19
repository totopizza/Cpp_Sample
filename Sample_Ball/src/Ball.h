
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


// TIPS: ��ʒ[�̏��
class Edge {
public:
  float sup;   // �ŏ��l
  float inf;   // �ő�l

  Edge(const float s, const float i) : sup(s), inf(i) {}
};

}
