
#pragma once
#include "scene_base.h"
#include "../Environment/number_draw.h"


class cMain : public cSceneBase {
  Random rand_;
  cNumber num_;

  int game_time_;

  struct {
    bool hit_;
    int move_time_;
    int hit_time_;
  } enemy;

  bool on_mouse_;
  Vec2f pos_;
  Vec2f slight_;
  const Vec2f size_;

  void timeInit();
  void enemyMove();

  void disp_logo();
  void disp_enemy();
  void disp_timeGauge();
  void disp_score();

public:
  cMain();

  bool quitGame();
  bool sceneChange();

  void update();
  void draw();
};
