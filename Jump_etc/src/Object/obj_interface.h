
#pragma once
#include "../common.hpp"


class cObject;


class cObjectInterface {

  // TODO: 機能のみを呼び出せるようにする
  //cObject* m_obj;

protected:

  // TODO: 機能のみを呼び出せるようにする
  //     : enum, std::map あたりを組み合わせればいけそうな気がする
  //     : std::function, ラムダ式も使えそう
  //     : 使い方が理解出来てないので勉強
  //bool getComponent();

  // FIXME: update() など、関係ないものまで呼び出せてしまうので解決したい
  //      : とりあえず動作確認してから改善方法を検討
  cObject* m_obj;

public:

  cObjectInterface(cObject*);

  virtual void update() = 0;
};
