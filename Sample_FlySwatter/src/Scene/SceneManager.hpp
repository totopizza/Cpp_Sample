
#pragma once
#include "../Common.hpp"
#include "Title.hpp"
#include "MainGame.h"
#include "Result.hpp"
#include <memory>
#include <map>


namespace common {

class SceneManager {
public:
  SceneManager() : is_close_(false) {
    current_scene_ = std::make_shared<Title>();
  }

  void update() {
    current_scene_->update();
    if (current_scene_->isFinish()) sceneChange();

    if (current_scene_->getSceneName() == SceneName::Result &&
        App::get().isPushButton(RIGHT)) {
      is_close_ = true;
    }
  }

  void draw() {
    App::get().begin();
    current_scene_->draw();
    App::get().end();
  }

  const bool isOpen() const {
    return App::get().isOpen() && !is_close_;
  }

private:
  bool is_close_;
  pScene current_scene_;

  void sceneChange() {
    typedef std::function<pScene()>  SceneMaker;
    std::map<SceneName, SceneMaker> SceneList = {
      { SceneName::Title, [] { return std::make_shared<Title>();  } },
      { SceneName::MainGame, [] { return std::make_shared<Main>();   } },
      { SceneName::Result, [] { return std::make_shared<Result>(); } },
    };

    const auto& next = current_scene_->getNextScene();
    current_scene_ = (SceneList.find(next)->second)();
  }
};

}
