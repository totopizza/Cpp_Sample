
#include "Common.h"
#include <map>


enum SpriteID {
  Player,
  Enemy,
  BackGround,

  All_Sprite,
};


enum SpriteSize {
  ObjectSize = 128,
  BackGround_W = 1024,
  BackGround_H = 512,
};


class Resource {
public:
  static Resource& get() {
    static Resource s_resource;
    return s_resource;
  }

  const Texture& sprite(const SpriteID id) {
    return sprite_.find(id)->second;
  }

private:
  std::map<SpriteID, Texture> sprite_;

  struct SpriteInfo {
    SpriteID id_;
    std::string pass_;
  };

  Resource() {
    const SpriteInfo tableData[] = {
      { Player,     "res/player.png" },
      { Enemy,      "res/enemy.png"  },
      { BackGround, "res/bg.png"     },
    };

    // ”ÍˆÍƒx[ƒX for •¶ (Range_Based_for_Statement)
    for (auto& it : tableData) {
      sprite_.insert(std::make_pair(it.id_, Texture(it.pass_)));
    }
  }
};
