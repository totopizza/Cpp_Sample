
#pragma once
#include "lib/framework.hpp"


enum WindowSize {
  WIDTH  = 512,
  HEIGHT = 512,
};


enum SceneState {
  TITLE,
  MAIN_GAME,
  RESULT,

  ALL_SCENE,
};


enum SpriteSize {
  CARD_W = 72,
  CARD_H = 96,
};


enum Common {
  FPS = 60,
  BLINK_SPEED = FPS / 4,
};
