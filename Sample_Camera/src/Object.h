
#include "Common.h"
#include "Resource.hpp"


struct ObjectData {
  SpriteID id_;

  Vec2f pos_;
  Vec2f size_;
  Vec2f offset_;
};


class Object {
public:
  enum {
    JumpPower = 20,
    MoveSpeed = 5,
  };

  Object(const SpriteID);

  void update(AppEnv&);
  void draw(const Vec2f&);

  const Vec2f& getPos() const { return own_.pos_; }

private:
  ObjectData own_;
};
