
//
// �}�N���̎���
// . Cinder �̃}�l�����Ă݂�
//

#include <iostream>

#define MAIN_EXECUTE(VALUE)                       \
  int main() {                                    \
    int* hoge = (int*)#VALUE;                     \
    std::cout << "hoge = " << *hoge << std::endl; \
  }

// main() �̎��s
MAIN_EXECUTE(NULL)

//
// ���s����
// . �����̎������悭�킩���
// . �Ƃ肠�����������ǁA���������f����ĂȂ�
//
