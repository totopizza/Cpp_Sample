
#include "App.hpp"
#include "Resource.h"
#include <ctime>
#include <fstream>


using namespace common;

Ranking::Ranking() : font_("res/mplus12r.ttf") {
  font_.size(FontSize);
  rand_.setSeed(u_int(time(nullptr)));
  scoreInit();
}


void Ranking::update() {
  const auto click = App::get().isPushButton(Mouse::LEFT);
  if (click) current_score_ = getRandomScore();
}


void Ranking::draw() {
  drawBack();
  drawRank();
  drawMyScore();
}


void Ranking::scoreInit() {
  std::ifstream fstr("res/score.txt");

  while (score_.size() < MaxRankNumber) {
    fstr ? initLoad(fstr) : initRandom();
  }

  current_score_ = getRandomScore();

  const auto isHigh = [](u_short& s1, u_short& s2) { return s1 > s2; };
  score_.sort(isHigh);
}


void Ranking::initLoad(std::ifstream& fstr) {
  int temp;
  fstr >> temp;

  // TIPS: 読み込んだデータに問題があれば、乱数で初期化
  if (temp <= 0 || temp > MaxScoreValue)
    temp = getRandomScore();

  score_.emplace_back(temp);
}


void Ranking::initRandom() {
  score_.emplace_back(getRandomScore());
}


const u_short Ranking::getRandomScore() {
  return rand_(1, MaxScoreValue);
}


void Ranking::drawBack() {
  drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
                 0, 0, 256, 256,
                 res::get().sprite(BackGround),
                 Color(1, 1, 1, 0.5f));
}


void Ranking::drawRank() {
  short temp_score;
  Vec2f pos;

  pos.x() = PointPos_X;
  is_draw_ = false;

  auto itr = score_.begin();
  for (int count = 0; count < MaxRankNumber; ++count) {
    pos.y() = PointPos_Y - count * Line_H;

    if (*itr > current_score_ || is_draw_) {
      temp_score = *itr;
      ++itr;
    }
    else {
      temp_score = current_score_;
      drawHere(count);
      is_draw_ = true;
    }

    drawPoint(pos, temp_score);
  }
}


void Ranking::drawMyScore() {
  const Vec2f PointPos(PointPos_X, ScorePos_Y);
  drawPoint(PointPos, current_score_);

  const float StringPos_Y = ScorePos_Y + StringOffset_Y;
  const Vec2f StringPos(StringPos_X, StringPos_Y);
  font_.draw("Score", StringPos, Color::white);
}


void Ranking::drawPoint(const Vec2f& pos0,
                        const int point) {
  Vec2f pos = pos0;

  const int Large = point / 10;
  for (int count = 0; count < Large; ++count) {
    drawTextureBox(pos.x(), pos.y(), PointSize_L, PointSize_L,
                   0, 0, TextureSize, TextureSize,
                   res::get().sprite(LargePoint));
    pos.x() += Line_W;
  }

  if (Large != 0) pos.x() += Line_W;

  const int Small = point % 10;
  for (int count = 0; count < Small; ++count) {
    drawTextureBox(pos.x(), pos.y(), PointSize_S, PointSize_S,
                   0, 0, TextureSize, TextureSize,
                   res::get().sprite(SmallPoint));
    pos.x() += Line_W;
  }
}


void Ranking::drawHere(const int count) {
  if (is_draw_) return;

  const float StringPos_Y = PointPos_Y - count * Line_H + StringOffset_Y;
  const Vec2f StringPos(StringPos_X, StringPos_Y);
  font_.draw("Here ->", StringPos, Color::yellow);
}
