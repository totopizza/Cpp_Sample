
// 2015/06/13
// �|�C���^�ƃX�}�[�g�|�C���^
// �R���\�[���A�v���P�[�V�����ɂ�铮��m�F�T���v��

#include <iostream>
#include <string>

// �X�}�[�g�|�C���^�̐錾�ɕK�v�ȃC���N���[�h�t�@�C��
#include <memory>


void Create(const std::string& name) { std::cout << "Create." << name << std::endl; }
void Delete(const std::string& name) { std::cout << "Delete." << name << std::endl; }


class Object {
public:
  Object(const std::string& n = "object") : name_(n) { Create(name_); }
  ~Object() { Delete(name_); }
  //virtual ~Object() { std::cout << "Delete.Object" << std::endl; }

protected:
  std::string name_;
};


class Player : public Object {
public:
  Player() : Object("player") { Create(name_); }
  ~Player() { Delete(name_); }
};


class Enemy : public Object {
public:
  Enemy() : Object("enemy") { Create(name_); }
  ~Enemy() { Delete(name_); }
};


int main() {
  const auto endl = [] { std::cout << std::endl; };

  // 1. �|�C���^�̐錾�A�������Ɖ��
  // NOTICE: �R���X�g���N�^�i�ƁA�f�X�g���N�^�j���Ă΂��^�C�~���O��m��
  {
    std::cout << "�|�C���^" << std::endl;

    // �e�N���X�̃|�C���^�ɐe�N���X�̃f�[�^������
    Object* obj = new Object();
    delete obj;
    endl();

    // �e�N���X�̃|�C���^�Ɏq�N���X�̃f�[�^������
    obj = new Player();
    delete obj;
    endl();
  }
  // �܂Ƃ�
  // . �p���֌W�ɂ���N���X�������ꍇ�ɗL��
  // . �������̉���Y��ɒ���

  // 2. �X�}�[�g�|�C���^�̎��
  // NOTICE: �������������I�ɉ�����Ă����̂ŁA����Y��̐S�z���Ȃ�
  {
    std::cout << "�X�}�[�g�|�C���^" << std::endl;

    // std::unique_ptr  ���j�[�N�|�C���^
    {
      std::cout << ">> ���j�[�N�|�C���^" << std::endl;
      Object* obj;   // ���j�[�N�ł͂Ȃ��|�C���^

      std::unique_ptr<Object> unique_obj = std::make_unique<Object>();

      // std::make_unique = �X�}�[�g�|�C���^�ł� new
      unique_obj = std::unique_ptr<Enemy>();
      endl();
    }
    
    // std::shared_ptr  �V�F�A�[�h�|�C���^
    {
      std::cout << ">> �V�F�A�[�h�|�C���^" << std::endl;
      std::shared_ptr<Object> shared_obj_1 = std::make_shared<Player>();
      std::shared_ptr<Object> shared_obj_2;
      shared_obj_2 = shared_obj_1;
    }
    endl();

    // �⑫: ���̑��̃X�}�[�g�|�C���^�ɂ���
    /*
     * std::auto_ptr  �I�[�g�|�C���^
     *   ��ԍŏ��ɍ��ꂽ�X�}�[�g�|�C���^�B
     *   �����ɒv���I�Ȍ��ׂ����������߂ɁA���j�[�N�|�C���^�ȂǁA
     *   ���̑��̃X�}�[�g�|�C���^������邱�ƂɂȂ����B
     *   ���݂ł́A�܂��g���Ȃ��X�}�[�g�|�C���^�B
     *
     * std::weak_ptr  �E�B�[�N�|�C���^
     *   �ʏ�A���ꂾ���Ŏg���邱�Ƃ͂Ȃ��B
     *   ��{�I�ɁA�V�F�A�[�h�|�C���^�ƈꏏ�Ɏg���B
     *   �}���`�X���b�h����������Ƃ��ɋ����B
     */
  }
  // �܂Ƃ�
  // . �����I�Ƀ�����������Ă����A��r�I���S�ȃ|�C���^
  // . std::shared_ptr ���g�����肪�悭�֗�
}
