
#pragma once
#include "../common.hpp"
#include "../Ranking/ranking.h"


class cExecApp {
  cRanking m_rank;

  bool m_is_close;

  void appClose();

public:
  cExecApp();

  void startUp();

  void update();
  void draw();

  bool isOpen();
};
