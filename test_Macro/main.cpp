
//
// マクロの実験
// . Cinder のマネをしてみる
//

#include <iostream>

#define MAIN_EXECUTE(VALUE)                       \
  int main() {                                    \
    int* hoge = (int*)#VALUE;                     \
    std::cout << "hoge = " << *hoge << std::endl; \
  }

// main() の実行
MAIN_EXECUTE(NULL)

//
// 実行結果
// . 引数の取り方がよくわからん
// . とりあえず動くけど、正しく反映されてない
//
