
#include "scene_manager.h"


void cSceneManager::sceneShift() {
  if (!m_current_scene->sceneFinish()) { return; }

  m_next_scene = m_current_scene->nextScene();
  m_current_scene = m_next_scene;

  m_next_scene = nullptr;
}


void cSceneManager::hideScreen() {
  drawFillBox(-WIDTH / 2, -HEIGHT / 2,
              WIDTH, HEIGHT,
              Color(0, 0, 0, m_alpha));
}


void cSceneManager::start(std::shared_ptr<cScene> start_scene) {
  m_obj.start();
  m_alpha = 0.0f;
  m_current_scene = start_scene;
}


void cSceneManager::update() {
  sceneShift();
  m_current_scene->update();

  if (m_current_scene->getScene() != MAIN_GAME) return;
  m_obj.update();
}


void cSceneManager::draw() {
  m_current_scene->draw();
  m_obj.drawScore();
}
