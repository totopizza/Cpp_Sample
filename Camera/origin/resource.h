
#include "common.h"
#include <map>


enum SpriteID {
  Player,
  Enemy,
  BackGround,

  All_Sprite,
};


enum SpriteSize {
  Object = 128,
  BackGround_W = 1024,
  BackGround_H = 512,
};


class cResource {
  std::map<SpriteID, Texture> graph_;

  cResource();

public:
  static cResource getInstance();

  Texture getSprite(const SpriteID);
};
