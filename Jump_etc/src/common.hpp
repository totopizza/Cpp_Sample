
#pragma once
#include "lib/framework.hpp"


enum WindowSize {
  WIDTH  = 512,
  HEIGHT = 512,
};


enum KeyList {
  ESCAPE = GLFW_KEY_ESCAPE,
  JUMP   = GLFW_KEY_SPACE,
};


enum SceneState {
  Title,
  MainGame,
  Ending,

  All_Scene,
};
