
#include "resource.h"
#include <string>


struct SpriteInfo {
  SpriteID id_;
  std::string pass_;
};


cResource::cResource() {
  const SpriteInfo tableData[] = {
    { Player,     "res/player.png" },
    { Enemy,      "res/enemy.png" },
    { BackGround, "res/bg.png" },
  };

  // Range_Based_For_Statement
  for (auto& it : tableData) {
    graph_.insert(std::make_pair(it.id_, Texture(it.pass_)));
  }
}


// TIPS: シングルトンでリソースを生成する
cResource cResource::getInstance() {
  static cResource resource;
  return resource;
}


Texture cResource::getSprite(const SpriteID id) {
  auto it = graph_.find(id);
  return it->second;
}
