
#include "scene_manager.h"


void cSceneManager::sceneShift() {
  if (!m_current_scene->sceneFinish()) { return; }

  m_next_scene = m_current_scene->nextScene();
  m_current_scene = m_next_scene;

  m_next_scene = nullptr;
}


void cSceneManager::start() {
  m_current_scene = std::make_shared<cMainGame>();
}


void cSceneManager::update() {
  sceneShift();
  m_current_scene->update();
}


void cSceneManager::draw() {
  m_current_scene->draw();
}
