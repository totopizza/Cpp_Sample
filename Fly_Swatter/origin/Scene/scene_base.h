
#pragma once
#include "../common.h"
#include "../src/lib/font.hpp"
#include "../Environment/environment.h"


enum {
  FONT_SIZE = 40,
};


class cSceneBase {
protected:
  Font text_;

public:
  cSceneBase();

  virtual bool quitGame() = 0;
  virtual bool sceneChange() = 0;

  virtual void update() = 0;
  virtual void draw() = 0;
};
