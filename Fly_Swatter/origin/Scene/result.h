
#pragma once
#include "scene_base.h"
#include "../Environment/number_draw.h"


class cResult : public cSceneBase {
  cNumber num_;
  int stop_time_;

  void disp_score();

public:
  cResult();

  bool quitGame();
  bool sceneChange();

  void update();
  void draw();
};
