
#include "common.h"
#include "resource.h"


struct ObjectData {
  SpriteID id_;

  Vec2f pos_;
  Vec2f size_;
  Vec2f offset_;
};


class cObject {
  ObjectData own_;

public:
  explicit cObject(const SpriteID);

  void update(AppEnv&);
  void draw(const Vec2f&);

  Vec2f getPos() const;
};
