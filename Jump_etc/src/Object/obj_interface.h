
#pragma once
#include "../common.hpp"


class cObject;


class cObjectInterface {

  // TODO: �@�\�݂̂��Ăяo����悤�ɂ���
  //cObject* m_obj;

protected:

  // TODO: �@�\�݂̂��Ăяo����悤�ɂ���
  //     : enum, std::map �������g�ݍ��킹��΂��������ȋC������
  //     : std::function, �����_�����g������
  //     : �g�����������o���ĂȂ��̂ŕ׋�
  //bool getComponent();

  // FIXME: update() �ȂǁA�֌W�Ȃ����̂܂ŌĂяo���Ă��܂��̂ŉ���������
  //      : �Ƃ肠��������m�F���Ă�����P���@������
  cObject* m_obj;

public:

  cObjectInterface(cObject*);

  virtual void update() = 0;
};
