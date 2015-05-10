
#pragma once
#include "../common.hpp"
#include "../FrameWork/resource.h"


class cBackGround {

  bool m_alpha_mode;
  float m_alpha;
  float m_fade_speed;

  void alphaPlaying();
  void alphaTypeChange();

  void drawBG(const resource::SpriteID);
  float getAlpha(const resource::SpriteID);

public:

  cBackGround();

  void update();
  void draw();
};
