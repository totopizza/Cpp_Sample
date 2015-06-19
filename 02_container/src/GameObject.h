
#pragma once
#include "Common.hpp"
#include <list>
#include <memory>


class Env {
public:

  // �V���O���g���ƌĂ΂��f�U�C���p�^�[��
  // TIPS: �v���O�������s���͐�΂ɂP�����Ȃ����Ƃ�ۏ؂���
  static AppEnv& get() {
    static AppEnv s_env(common::WIDTH, common::HEIGHT, false, true);
    return s_env;
  }

private:
  Env() = default;
};


// �ʖ��錾
typedef std::shared_ptr<class GameObject>  pObject;
typedef std::list<pObject>                 ObjectList;

// �p�����ɂȂ�e�N���X
// TIPS:
//  �e�N���X�̃|�C���^���g���ăR���e�i���񂷏ꍇ�A
//  �K�����z�֐���p�ӂ��邱��
class GameObject {
public:

  // �R���X�g���N�^
  // TIPS: �������Ȃ����Ƃ𖾎��I�ɂ���
  GameObject() = default;

  // ���z�f�X�g���N�^
  virtual ~GameObject() = default;

  // ���z�֐�
  // TIPS: �e�N���X�̃|�C���^����A�q���N���X�̋@�\���g����悤�ɂ���
  // TIPS: �C�ɂȂ�����Avirtual ���O���ăv���O���������s���Ă݂悤
  virtual void update() {}
  virtual void draw() {}

  // �R���e�i�i�V���O���g���j
  // TIPS: static �������֐��́A�ǂ�����ł��g����悤�ɂȂ�
  static std::list<pObject>& getObject() {
    static ObjectList s_list;
    return s_list;
  }

  // ��ʊO�̃V���b�g���������� (cpp)
  static void objectKill();

protected:
  Texture texture_;
  Vec2f size_;

  Vec2f pos_;
  int   dir_;         // ����
  float vel_;         // ���x

  short blink_;       // ���@�̓_�ŏ��
  short time_;        // �_�Ń^�C�}�[

  short dead_time_;   // ���S����

  // �������v�Z���āA��]�ʂ�Ԃ�
  const float getDirection() const { return dir_ * M_PI / 2; }

  // �ړ������Ƒ��x�̌v�Z (cpp)
  const Vec2f getVelocity();

  // ����ł邩����
  const bool isDead() const { return dead_time_ == 0; }
};


class Shot : public GameObject {
public:

  // �R���X�g���N�^ (cpp)
  // TIPS: ���˂��ꂽ�Ƃ��ɁA���@�̏����󂯎��
  Shot(const Vec2f&, const int);

  // �����̈ʒu���X�V����
  void update() {
    pos_ += getVelocity();
    removeCheck();
  }

  // �\��
  void draw() {
    drawTextureBox(pos_.x(), pos_.y(), size_.x(), size_.y(),
                   0, 0, size_.x(), size_.y(),
                   texture_, Color::white,
                   getDirection(),
                   Vec2f::Ones(), size_ / 2);
  }

private:

  // �����i�V���b�g�j����ʊO�ɏo�����`�F�b�N����
  void removeCheck() {
    const Vec2f w_size(common::WIDTH, common::HEIGHT);

    // ��ʊO�Ȃ玀�񂾂��Ƃɂ��� = �폜�ł���悤�ɂ���
    if (pos_.x() < -w_size.x() / 2 || pos_.x() > w_size.x() / 2 ||
        pos_.y() < -w_size.y() / 2 || pos_.y() > w_size.y() / 2) {
      dead_time_ = 0;
    }
  }
};


class Player : public GameObject {
public:

  // (cpp)
  Player();

  void update();
  void draw();

private:

  // �摜�̐؂�ւ�
  void blinkUpdate() {
    blink_ = (time_ / 15) % 2;

    ++time_;
    if (time_ < 60) return;

    time_ = 0;
  }
};
