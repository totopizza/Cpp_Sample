
#include "Resource.h"
#include <string>


Resource::Resource() {
  struct SpriteInfo {
    SpriteID id;
    std::string file_pass;
  };

  const SpriteInfo Table[] = {
    { LargePoint, "res/point_large.png" },
    { SmallPoint, "res/point_small.png" },
    { BackGround, "res/background.png"  },
  };

  for (auto& it : Table) {
    const auto sprite = std::make_pair(it.id, Texture(it.file_pass));
    sprite_.emplace(sprite);
  }
}


const Texture& res::sprite(const SpriteID id) const {
  return sprite_.find(id)->second;
}
