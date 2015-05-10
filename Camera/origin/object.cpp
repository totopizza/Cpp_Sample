
#include "object.h"


enum {
  JumpPower = 20,
  MoveSpeed = 5,
};


cObject::cObject(const SpriteID id) {
  const Vec2f ObjectSize = Vec2f(Object, Object);
  const Vec2f BgSize = Vec2f(BackGround_W, BackGround_H);

  const ObjectData tableData[] = {
    { Player, Vec2f(100, 20), ObjectSize, ObjectSize / 2 },
    { Enemy, Vec2f(800, 200), ObjectSize, ObjectSize / 2 },
    { BackGround, Vec2f(0, 0), BgSize, Vec2f(0, 0) },
  };

  // Range_Based_For_Statement
  for (int i = 0; i < All_Sprite; ++i) {
    if (id == tableData[i].id_) { own_ = tableData[i]; }
  }
}


void cObject::update(AppEnv& env) {

  // FIXME: –Ê“|‚¾‚Á‚½‚Ì‚ÅˆÚ“®”ÍˆÍ‚Ì§ŒÀ‚Í‚µ‚Ä‚¢‚È‚¢
  if (env.isPressKey('W')) { own_.pos_.y() += MoveSpeed; }
  if (env.isPressKey('S')) { own_.pos_.y() -= MoveSpeed; }
  if (env.isPressKey('A')) { own_.pos_.x() -= MoveSpeed; }
  if (env.isPressKey('D')) { own_.pos_.x() += MoveSpeed; }
}


void cObject::draw(const Vec2f& camera) {

  // TIPS: Ž©g‚ÌID‚É‘Î‰ž‚µ‚½‰æ‘œ‚ðŽæ“¾
  Texture& own = cResource::getInstance().getSprite(own_.id_);

  // TIPS: ƒJƒƒ‰‚ÆŽ©•ª‚Ì‘Š‘ÎÀ•W‚ð‹‚ß‚é
  const Vec2f DrawPos = own_.pos_ - camera;

  const Color White = Color(1, 1, 1);
  const Vec2f Scale = Vec2f(1, 1);

  drawTextureBox(DrawPos.x(), DrawPos.y(),
                 own_.size_.x(), own_.size_.y(),
                 0, 0,
                 own_.size_.x(), own_.size_.y(),
                 own, White,
                 0, Scale, own_.offset_);
}


Vec2f cObject::getPos() const {
  return own_.pos_;
}
