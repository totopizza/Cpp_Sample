
#pragma once
#include <queue>
#include "../common.hpp"


class cCard {

  enum {
    CARD_MAX = 53,
    CARD_NUMBER = 13,
  };

  std::queue<int> m_card_number;

  Random m_rand;
  const Vec2f m_SIZE;

  void cardInit();

public:

  cCard();

  void start();

  void update();
  void draw();
};
