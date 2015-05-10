
#pragma once
#include "../common.h"
#include "../Environment/environment.h"
#include "title.h"
#include "main_game.h"
#include "result.h"


class cSceneManager {
  cSceneBase* play_scene_;

  enum SceneState {
    Title,
    Main,
    Result,
  };

  typedef SceneState  state;
  SceneState current_scene_;

  void sceneChange();

public:
  cSceneManager();

  void run();
};
