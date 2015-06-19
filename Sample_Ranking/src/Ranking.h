
#pragma once
#include "Common.hpp"
#include <list>


namespace common {

typedef unsigned short  u_short;

class Ranking {
public:
  Ranking();

  void update();
  void draw();

private:
  enum Parameter {
    FontSize    = 32,
    TextureSize = 80,

    MaxRankNumber = 10,
    MaxScoreValue = 50,

    Line_W = FontSize / 8 * 6,
    Line_H = FontSize / 8 * 16,

    PointSize_L = TextureSize / 10 * 8,
    PointSize_S = PointSize_L / 4 * 3,
    PointPos_X  = -Line_W * 3,
    PointPos_Y  = HEIGHT / 2 - 200,

    ScorePos_Y  = PointPos_Y + 110,
    StringPos_X = -WIDTH / 2 + 80,
    StringOffset_Y = 20,
  };

  typedef std::list<u_short>  Score;
  typedef Score::iterator     ScoreItr;
  Score score_;
  short current_score_;
  bool is_draw_;

  Font   font_;
  Random rand_;

  void scoreInit();
  void initLoad(std::ifstream&);
  void initRandom();
  const u_short getRandomScore();

  void drawBack();
  void drawRank();
  void drawMyScore();

  void drawPoint(const Vec2f&, const int);
  void drawHere(const int);
};

}
