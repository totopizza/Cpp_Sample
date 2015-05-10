
#pragma once
#include "scene_base.h"


class cTitle : public cSceneBase {
public:
  cTitle();

  bool quitGame();
  bool sceneChange();

  void update();
  void draw();
};
