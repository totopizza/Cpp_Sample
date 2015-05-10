
#pragma once
#include "../common.hpp"
#include <map>


enum SpriteID {
  LargePoint,
  SmallPoint,
  BackGround,

  All_Sprite,
};


class cResource {
  cResource();

  std::map<SpriteID, Texture> m_sprite;
  std::map<SpriteID, Color>   m_color;

public:
  static cResource* get();

  Texture* sprite(const SpriteID id);
  Color* color(const SpriteID id);
};

typedef cResource  res;
