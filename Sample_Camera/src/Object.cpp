
#include "Object.h"


Object::Object(const SpriteID id) {
  const Vec2f ObjSize = Vec2f(ObjectSize, ObjectSize);
  const Vec2f BgSize = Vec2f(BackGround_W, BackGround_H);

  const ObjectData tableData[] = {
    { Player,     Vec2f(100, 20),  ObjSize, ObjSize / 2 },
    { Enemy,      Vec2f(800, 200), ObjSize, ObjSize / 2 },
    { BackGround, Vec2f(0, 0),     BgSize,  Vec2f(0, 0) },
  };

  // 範囲ベース for 文 (Range_Based_for_Statement)
  for (int i = 0; i < All_Sprite; ++i) {
    if (id == tableData[i].id_) { own_ = tableData[i]; }
  }
}


void Object::update(AppEnv& env) {

  // FIXME: 面倒だったので移動範囲の制限はしていない
  if (env.isPressKey('W')) { own_.pos_.y() += MoveSpeed; }
  if (env.isPressKey('S')) { own_.pos_.y() -= MoveSpeed; }
  if (env.isPressKey('A')) { own_.pos_.x() -= MoveSpeed; }
  if (env.isPressKey('D')) { own_.pos_.x() += MoveSpeed; }
}


void Object::draw(const Vec2f& camera) {

  // TIPS: 自身のIDに対応した画像を取得
  const Texture& own = Resource::get().sprite(own_.id_);

  // TIPS: カメラと自分の相対座標を求める
  const Vec2f DrawPos = own_.pos_ - camera;

  const auto& Size = own_.size_;

  drawTextureBox(DrawPos.x(), DrawPos.y(), Size.x(), Size.y(),
                 0, 0, Size.x(), Size.y(),
                 own, Color::white,
                 0, Vec2f::Ones(), own_.offset_);
}
