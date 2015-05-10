
#pragma once
#include <memory>
#include "environment.h"
#include "../Scene/exec_main.h"


class cSceneManager {

  std::shared_ptr<cScene> m_current_scene;
  std::shared_ptr<cScene> m_next_scene;

  void sceneShift();

public:

  cSceneManager() = default;

  void start();

  void update();
  void draw();
};
