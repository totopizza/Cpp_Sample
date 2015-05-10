
#pragma once
#include "../common.hpp"
#include <list>


class cRanking {
  Font   m_font;
  Random m_rand;

  int m_my_score;
  bool m_is_check;
  std::list<int> m_rank;

  void scoreInit();
  void initLoad(std::ifstream&);
  void initRandom();

  int getRandomScore();
  bool isHighLowCheck(const int);

  void drawPoint(const Vec2f&, const int);

  void drawBack();
  void drawRank();
  void drawHere(const int);
  void drawMyScore();

public:
  cRanking();

  void start();

  void update();
  void draw();
};
