
#pragma once
#include "../common.hpp"


class cScore {

  int  m_score;
  const std::string m_STR;

  Font m_font;
  const Vec2f m_POS;

public:

  cScore();

  void start();

  void scoreAdd();
  void scoreInit();

  void draw();
};
