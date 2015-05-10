
#pragma once
#include "scene.hpp"


class cTitle : public cScene {

  short m_blink;

public:

  cTitle();

  void update();
  void draw();

  SceneState getScene() const;
  std::shared_ptr<cScene> nextScene() const;
};
