
#include "Ball.h"

using namespace common;


const Edge Horizon(-WIDTH / 2, WIDTH / 2);      // ���E
const Edge Vertical(-HEIGHT / 2, HEIGHT / 2);   // �㉺


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

  // �����W�̔��ˏ���
  if (pos_.x() < Horizon.sup || pos_.x() > Horizon.inf) {

    // TIPS: ���x�𔽑Ε����ɂ���
    speed_.x() *= Sign;

    // TIPS: ��ʒ[�ƌ��݂̈ʒu���r�A
    // * ���[��菬������΍��[�ɖ߂� (std::max())
    // * �E�[���傫����ΉE�[�ɖ߂� (std::min())
    pos_.x() = std::max(pos_.x(), Horizon.sup);
    pos_.x() = std::min(pos_.x(), Horizon.inf);

    // * ���ꂼ��A��r�������ʁA�傫���ق��A�������ق���Ԃ�
    // * ���[��菬���� = ���̉�ʊO�ɂ͂ݏo�� = ���[���u�傫���v
    // * �E�[���傫�� = �E�̉�ʊO�ɂ͂ݏo�� = �E�[���u�������v
    // * ��₱�������ǁA�֗��Ȏg�����Ȃ̂ł��Њo���Ă�����

    // * ���Ȃ݂ɁA�搶�̃T���v�� camera �ł��g�p���Ă���
  }

  // �����W�̔��ˏ���
  // TIPS: ��ɓ���
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
