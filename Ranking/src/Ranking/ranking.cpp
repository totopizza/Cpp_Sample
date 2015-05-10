
#include "../System/environment.h"
#include "../System/resource.h"
#include "ranking.h"
#include <ctime>
#include <fstream>


enum {
  FontSize = 40,

  Ranking = 10,
  ScoreMax = 50,

  SpriteSize = 80,

  Rane_W = 20,
  Rane_H = 64,

  PointSize_L = 60,
  PointSize_S = 40,
  PointPos_X = -20,
  PointPos_Y = HEIGHT / 2 - 200,

  MyScorePos_Y = HEIGHT / 2 - 90,
  StringPos_X = -WIDTH / 2 + 80,
  StringPos_H = 20,
};


cRanking::cRanking() :
m_font("res/mplus12r.ttf") {
}


void cRanking::scoreInit() {
  std::ifstream fstr("res/score.txt");

  while (m_rank.size() < Ranking) {
    fstr
      ? initLoad(fstr)
      : initRandom();
  }

  m_my_score = getRandomScore();
  m_rank.sort();
}


void cRanking::initLoad(std::ifstream& fstr) {
  int temp;
  fstr >> temp;

  // TIPS: 読み込んだデータに問題があれば、乱数で初期化
  if (temp <= 0) temp = getRandomScore();

  m_rank.emplace_back(temp);
}


void cRanking::initRandom() {
  m_rank.emplace_back(getRandomScore());
}


int cRanking::getRandomScore() {
  return m_rand(1, ScoreMax);
}


// TIPS: 自分のスコアをランキングに反映済みなら問答無用で false を返す
bool cRanking::isHighLowCheck(const int rank_score) {
  return m_my_score >= rank_score && !m_is_check;
}


void cRanking::drawPoint(const Vec2f& pos0,
                         const int point) {
  Vec2f pos = pos0;

  const int Large = point / 10;
  for (int count = 0; count < Large; ++count) {
    drawTextureBox(pos.x(), pos.y(), PointSize_L, PointSize_L,
                   0, 0, SpriteSize, SpriteSize,
                   *res::get()->sprite(LargePoint),
                   *res::get()->color(LargePoint));
    pos.x() += Rane_W;
  }

  if (Large != 0) pos.x() += Rane_W;

  const int Small = point % 10;
  for (int count = 0; count < Small; ++count) {
    drawTextureBox(pos.x(), pos.y(), PointSize_S, PointSize_S,
                   0, 0, SpriteSize, SpriteSize,
                   *res::get()->sprite(SmallPoint),
                   *res::get()->color(SmallPoint));
    pos.x() += Rane_W;
  }
}


void cRanking::drawBack() {
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
                 0, 0, 256, 256,
                 *res::get()->sprite(BackGround),
                 *res::get()->color(BackGround));
}


void cRanking::drawRank() {
  int temp_score;
  Vec2f pos;

  m_is_check = false;
  auto it = m_rank.rbegin();
  auto end = m_rank.rend();

  for (int count = 0; count < Ranking; ++count) {
    pos.x() = PointPos_X;
    pos.y() = PointPos_Y - count * Rane_H;

    if (isHighLowCheck(*it)) {
      temp_score = m_my_score;
      m_is_check = true;
      drawHere(count);
    } else {
      temp_score = *it;
      ++it;
    }

    drawPoint(pos, temp_score);
  }
}


void cRanking::drawHere(const int count) {
  const float StringPos_Y = PointPos_Y - count * Rane_H + StringPos_H;
  const Vec2f StringPos(StringPos_X, StringPos_Y);
  m_font.draw("Here ->", StringPos, Color::yellow);
}


void cRanking::drawMyScore() {
  const Vec2f PointPos(PointPos_X, MyScorePos_Y);
  drawPoint(PointPos, m_my_score);

  const float StringPos_Y = MyScorePos_Y + StringPos_H;
  const Vec2f StringPos(StringPos_X, StringPos_Y);
  m_font.draw("Score", StringPos, Color::white);
}


void cRanking::start() {
  m_font.size(FontSize);
  m_rand.setSeed(u_int(time(nullptr)));
  scoreInit();
}


void cRanking::update() {
  if (env::get()->isPushButton(Mouse::LEFT))
    m_my_score = getRandomScore();
}


void cRanking::draw() {
  drawBack();
  drawRank();
  drawMyScore();
}
