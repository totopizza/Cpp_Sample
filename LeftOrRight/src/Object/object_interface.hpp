
#pragma once
#include "../common.hpp"


class cObject;

class cObjectInterface {
protected:

  cObjectInterface(cObject* obj) :
    mp_obj(obj) {}

  cObject* mp_obj;

public:

  virtual void update() = 0;
};
