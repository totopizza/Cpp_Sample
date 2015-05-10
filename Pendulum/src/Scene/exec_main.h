
#pragma once
#include "scene.hpp"


class cExecMain : public cScene {
  float m_angle;

public:

  cExecMain();

  void update();
  void draw();

  SceneState getScene()  const;
  std::shared_ptr<cScene> nextScene() const;

  bool sceneFinish() const;
};
