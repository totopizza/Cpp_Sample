
#pragma once
#include "Common.hpp"
#include <fstream>
#include <vector>


namespace common {

class Score {
public:
  static Score& get() {
    static Score s_score;
    return s_score;
  }

  void countReset() { score_ = 0; }
  void countUp() { ++score_; }
  void countPushBack() { ranking_.emplace_back(score_); }

  void rankingSort() {
    const auto greater_than = [](int s1, int s2) { return s1 > s2; };
    std::sort(ranking_.begin(), ranking_.end(), greater_than);
    if (ranking_.size() > 3) ranking_.pop_back();
  }

  const bool highScoreUpdate() {
    return std::count(ranking_.begin(), ranking_.end(), score_) != 0;
  }

  void drawCurrentScore() {
    const Vec2f pos(-WIDTH / 2 + 20, -HEIGHT / 2 + 15);
    std::ostringstream score;
    score << "score: " << score_;
    font_.draw(score.str(), pos, Color::cyan);
  }

  void drawRankingScore() {
    short index = 0;
    Vec2f pos;
    pos.x() = -WIDTH / 2 + 20;

    for (auto& it : ranking_) {
      if (it == 0) continue;

      std::ostringstream score;
      score << 1 + index << ": " << it;

      pos.y() = HEIGHT / 2 - (1 + index) * FontSize - 5;

      font_.draw(score.str(), pos, Color::cyan);
      ++index;
    }
  }

  void scoreSave() {
    std::ofstream save("res/score.txt");
    if (!save) return;

    for (auto& it : ranking_) { save << it << std::endl; }
  }

  void scoreLoad() {
    std::ifstream load("res/score.txt");
    if (!load) return;

    short temp;
    for (short i = 0; i < 3; ++i) {
      load >> temp;
      ranking_.emplace_back(temp);
    }
  }

private:
  Font font_;

  short score_;
  std::vector<short> ranking_;

  Score() : font_("res/MeiryoConsolas.ttf") {
    font_.size(FontSize);
  }
};

}

void scoreSave(const int score);
