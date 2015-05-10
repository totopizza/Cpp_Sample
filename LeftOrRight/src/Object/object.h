
#pragma once
#include "../common.hpp"
#include "card.h"
#include "score.h"


class cObject {

  cCard  m_card;
  cScore m_score;

public:

  cObject();

  void start();

  void update();

  void drawCard();
  void drawScore();
};
