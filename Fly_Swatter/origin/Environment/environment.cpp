
#include "environment.h"


std::unique_ptr<AppEnv> env::app_;
std::unique_ptr<Media> env::se_;
Vec2f env::mouse_pos_;
int env::score;


void env::execApplication() {
  if (app_ != nullptr) { return; }
  app_ = std::make_unique<AppEnv>(WIDTH, HEIGHT, false, true);
  se_ = std::make_unique<Media>("res/hit.wav");

  const float volume = 0.5f;
  se_->gain(volume);
}


void env::mousePosUpdate() {
  mouse_pos_ = app_->mousePosition();
}


void env::sePlay() {
  se_->play();
}


void env::setupDraw() {
  app_->setupDraw();
}


void env::update() {
  app_->update();
}


bool env::isOpen() {
  return app_->isOpen();
}


bool env::leftClick() {
  return app_->isPushButton(Mouse::LEFT);
}


bool env::rightClick() {
  return app_->isPushButton(Mouse::RIGHT);
}


bool env::rectOnMouse(const Vec2f& pos,
                      const Vec2f& size) {
  if (mouse_pos_.x() > pos.x() && mouse_pos_.x() < pos.x() + size.x() &&
      mouse_pos_.y() > pos.y() && mouse_pos_.y() < pos.y() + size.y()) {
    return true;
  }

  return false;
}
