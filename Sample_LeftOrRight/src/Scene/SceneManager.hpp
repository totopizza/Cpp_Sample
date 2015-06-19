
#pragma once
#include "../Common.hpp"
#include "Title.hpp"
#include "MainGame.h"
#include "Result.hpp"
#include <map>


class SceneManager {
public:
  SceneManager() {
    current_scene_ = std::make_shared<Title>();
  }

  void update() {
    current_scene_->update();
    if (current_scene_->isFinish()) sceneChange();
  }

  void draw() {
    current_scene_->draw();
  }

private:
  pScene current_scene_;

  void sceneChange() {
    typedef SceneName                Name;
    typedef std::function<pScene()>  SceneMaker;
    std::map<Name, SceneMaker> SceneList = {
      { Name::Title,    [] { return std::make_shared<Title>();    } },
      { Name::MainGame, [] { return std::make_shared<MainGame>(); } },
      { Name::Result,   [] { return std::make_shared<Result>();   } },
    };

    const auto& next = current_scene_->getNextScene();
    current_scene_ = (SceneList.find(next)->second)();
  }
};
