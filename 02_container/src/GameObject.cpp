
#include "GameObject.h"


// 移動方向の計算
const Vec2f GameObject::getVelocity() {
  Vec2f tv;
  tv.x() = -std::sin(getDirection()) * vel_;
  tv.y() = std::cos(getDirection()) * vel_;
  return tv;
}


void GameObject::objectKill() {
  auto& list = getObject();

  // イテレーターを準備
  auto itr = list.begin();

  // イテレーターがコンテナの末尾に進むまでループ
  while (itr != list.end()) {

    // オブジェクトが死んでるかチェックする
    itr->get()->isDead()
      
      // 死んでたらコンテナから削除
      ? itr = list.erase(itr)

      // 死んでなかったらイテレーターを進める
      : ++itr;
  }

  // ３項演算子 ( ? : ) を使っています
}


// ショットの初期化
Shot::Shot(const Vec2f& pos, const int dir) {
  texture_ = Texture("res/shot.png");
  size_ = Vec2f(32, 32);

  pos_ = pos;
  dir_ = dir;
  vel_ = 3.0f;

  dead_time_ = -1;
}


// 自機の初期化
Player::Player() {
  texture_ = Texture("res/player.png");
  size_ = Vec2f(64, 64);

  pos_ = Vec2f(0, 0);
  dir_ = common::UP;
  vel_ = 2.0f;

  dead_time_ = -1;
}


void Player::update() {
  AppEnv& env = Env::get();

  // ラムダ式
  // TIPS: 超便利
  const auto move = [&] { pos_ += getVelocity(); };

  if (env.isPressKey(GLFW_KEY_W)) {
    dir_ = common::UP;
    move();
  }
  if (env.isPressKey(GLFW_KEY_S)) {
    dir_ = common::DOWN;
    move();
  }
  if (env.isPressKey(GLFW_KEY_A)) {
    dir_ = common::LEFT;
    move();
  }
  if (env.isPressKey(GLFW_KEY_D)) {
    dir_ = common::RIGHT;
    move();
  }

  // ショット発射の判定
  if (env.isPushKey(GLFW_KEY_SPACE)) {

    // ショットに自機の座標、向きを渡してコンテナに追加
    getObject().push_back(pObject(new Shot(pos_, dir_)));
  }
}


void Player::draw() {
  blinkUpdate();

  drawTextureBox(pos_.x(), pos_.y(), size_.x(), size_.y(),
                 blink_ * size_.x(), 0, size_.x(), size_.y(),
                 texture_, Color::white,
                 getDirection(),
                 Vec2f::Ones(), size_ / 2);
}
