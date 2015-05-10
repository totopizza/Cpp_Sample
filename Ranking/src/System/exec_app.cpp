
#include "environment.h"
#include "exec_app.h"


cExecApp::cExecApp() :
m_is_close(false) {
}


void cExecApp::appClose() {
  m_is_close = env::get()->isPushKey(GLFW_KEY_ESCAPE);
}


void cExecApp::startUp() {
  m_rank.start();
}


void cExecApp::update() {
  m_rank.update();
  appClose();
}


void cExecApp::draw() {
  env::get()->begin();
  m_rank.draw();
  env::get()->end();
}


bool cExecApp::isOpen() {
  return env::get()->isOpen() && !m_is_close;
}
