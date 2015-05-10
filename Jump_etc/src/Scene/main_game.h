
#pragma once
#include "scene.hpp"
#include "../Object/object.h"
#include "../Object/back_ground.h"


class cMainGame : public cScene {

  // TIPS: Sample -> Jump
  cObject m_obj;

  // TIPS: Sample -> LineScroll, SceneSample
  cBackGround m_bg;

  // TIPS: Sample -> Text_Read.
  void textRead();

public:

  cMainGame();

  void update();
  void draw();

  SceneState getScene()  const;
  std::shared_ptr<cScene> nextScene() const;

  bool sceneFinish() const;
};
