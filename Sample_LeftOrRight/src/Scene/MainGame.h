
#pragma once
#include "SceneBase.hpp"
#include <vector>
#include <queue>


class MainGame : public SceneBase {
public:
  MainGame();

  void update();
  void draw();

private:
  enum {
    CARD_MAX = 52,
    CARD_NUM = 13,
    CARD_MARK = 4,

    CARD_W = 72,
    CARD_H = 96,
  };

  struct CardParam {
    int num, mark;
  };
  typedef std::pair<CardParam, CardParam>  CardPair;
  std::queue<CardPair> card_;

  Texture texture_;
  Random rand_;
  const int limit_;

  void cardInit();
  void drawCard(const CardParam&, const Vec2f&);

  void gameFinish();
};
