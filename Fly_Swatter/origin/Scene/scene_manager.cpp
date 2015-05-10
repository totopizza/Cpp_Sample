
#include "scene_manager.h"

typedef cSceneManager  scene;


cSceneManager::cSceneManager() :
current_scene_(state::Title) {
  play_scene_ = new cTitle();
}


void scene::sceneChange() {
  switch (current_scene_) {
    case state::Title:
      if (env::leftClick()) {
        current_scene_ = state::Main;
        play_scene_ = new cMain();
      }
      break;

    case state::Main:
      if (play_scene_->sceneChange()) {
        current_scene_ = state::Result;
        play_scene_ = new cResult();
      }
      break;

    case state::Result:
      if (play_scene_->sceneChange()) {
        current_scene_ = state::Title;
        play_scene_ = new cTitle();
      }
      break;

    default:;   // do not act.
  }
}


void scene::run() {
  while (env::isOpen() && !play_scene_->quitGame()) {
    env::mousePosUpdate();

    play_scene_->update();
    sceneChange();

    env::setupDraw();
    play_scene_->draw();
    env::update();
  }
}
