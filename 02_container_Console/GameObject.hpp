
#pragma once
#include <iostream>
#include <memory>
#include <list>


void Output(const std::string& str) {
  std::cout << str.c_str() << std::endl;
}


typedef std::shared_ptr<class GameObject>  pObject;
class GameObject {
public:
  GameObject() { Output("Create.Object"); }
  virtual ~GameObject() { Output("Delete.Object\n"); }

  virtual void update() {}
  virtual void draw() {}

  static std::list<pObject>& getList() {
    static std::list<pObject> object_;
    return object_;
  }

protected:
};


class Player : public GameObject {
public:
  Player() { Output(">> Create.Player\n"); }
  ~Player() { Output(">> Delete.Player"); }

  void update() { Output(".... Player.Update"); }
};


class Shot : public GameObject {
public:
  Shot() { Output(">> Create.Shot\n"); }
  ~Shot() { Output(">> Delete.Shot"); }

  void draw() { Output(".... Draw.Shot"); }
};
