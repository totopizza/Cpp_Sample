
#pragma once
#include "scene.hpp"


class cResult : public cScene {

  short m_blink;

public:

  cResult();

  void update();
  void draw();

  SceneState getScene() const;
  std::shared_ptr<cScene> nextScene() const;
};
