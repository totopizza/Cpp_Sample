
#include "Ball.h"

using namespace common;


const Edge Horizon(-WIDTH / 2, WIDTH / 2);      // 左右
const Edge Vertical(-HEIGHT / 2, HEIGHT / 2);   // 上下


Ball::Ball(const Vec2f& pos,
           Random& random) {
  pos_ = pos;

  speed_.x() = random(-10.0f, 10.0f);
  speed_.y() = random(-10.0f, 10.0f);

  color_.r(random(0.25f, 1.0f));
  color_.g(random(0.25f, 1.0f));
  color_.b(random(0.25f, 1.0f));
}


void Ball::gravity() {
  const float gravityPower = 1.0f;
  speed_.y() -= gravityPower;
}


void Ball::update() {
  const int Sign = -1;

  pos_.x() += speed_.x();
  pos_.y() += speed_.y();

  // ｘ座標の反射処理
  if (pos_.x() < Horizon.sup || pos_.x() > Horizon.inf) {

    // TIPS: 速度を反対方向にする
    speed_.x() *= Sign;

    // TIPS: 画面端と現在の位置を比較、
    // * 左端より小さければ左端に戻す (std::max())
    // * 右端より大きければ右端に戻す (std::min())
    pos_.x() = std::max(pos_.x(), Horizon.sup);
    pos_.x() = std::min(pos_.x(), Horizon.inf);

    // * それぞれ、比較した結果、大きいほう、小さいほうを返す
    // * 左端より小さい = 左の画面外にはみ出る = 左端が「大きい」
    // * 右端より大きい = 右の画面外にはみ出る = 右端が「小さい」
    // * ややこしいけど、便利な使い方なのでぜひ覚えておこう

    // * ちなみに、先生のサンプル camera でも使用している
  }

  // ｙ座標の反射処理
  // TIPS: 上に同じ
  if (pos_.y() < Vertical.sup || pos_.y() > Vertical.inf) {

    speed_.y() *= Sign;

    pos_.y() = std::max(pos_.y(), Vertical.sup);
    pos_.y() = std::min(pos_.y(), Vertical.inf);
  }
}


void Ball::draw() {
  drawFillCircle(pos_.x(), pos_.y(),
                 BallSize, BallSize,
                 BallDivision, color_);
}
