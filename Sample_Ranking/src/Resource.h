
#pragma once
#include "Common.hpp"


enum SpriteID {
  LargePoint,
  SmallPoint,
  BackGround,

  All_Sprite,
};


class Resource {
public:
  static Resource& get() {
    static Resource s_instance;
    return s_instance;
  }

  const Texture& sprite(const SpriteID id) const;

private:
  std::map<SpriteID, Texture> sprite_;

  Resource();
};

typedef Resource  res;
