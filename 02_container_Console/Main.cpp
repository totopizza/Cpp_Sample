
#include "GameObject.hpp"


int main() {
  const auto endl = [] { std::cout << std::endl; };

  GameObject::getList().push_back(pObject(new Player()));
  for (int i = 0; i < 5; ++i)
    GameObject::getList().push_back(pObject(new Shot()));

  auto list = GameObject::getList();
  for (auto& it : list) it->update();
  for (auto& it : list) it->draw();

  endl();
}
