
#pragma once
#include "common.h"


struct sCamera {
  Vec2f pos_;
  Vec2f area_inf_;
  Vec2f area_sup_;

  void initCamera(const Vec2f&, const Vec2f&);
  void updateCamera(const Vec2f&);
};


// TIPS: ��ʃT�C�Y�ɑΉ������A�ŏ��ƍő�̍��W�����߂�
void sCamera::initCamera(const Vec2f& inf, const Vec2f& sup) {
  const Vec2f WindowSize = Vec2f(WIDTH / 2, HEIGHT / 2);

  pos_ = Vec2f(0, 0);
  area_inf_ = inf + WindowSize;
  area_sup_ = sup - WindowSize;
}


// TIPS: �ΏۃI�u�W�F�N�g�𒆐S�ɑ�����悤�ɃJ�������X�V
void sCamera::updateCamera(const Vec2f& obj_pos) {
  const Vec2f delta = obj_pos - pos_;
  const float deltaRatio = 0.1f;

  pos_ += delta * deltaRatio;

  pos_.x() = std::max(pos_.x(), area_inf_.x());
  pos_.x() = std::min(pos_.x(), area_sup_.x());

  pos_.y() = std::max(pos_.y(), area_inf_.y());
  pos_.y() = std::min(pos_.y(), area_sup_.y());
}
