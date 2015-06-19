
/* 2Dゲームのカメラを動かすサンプルプログラム */
// . enum        列挙体
// . struct      構造体
// . class       クラス
// . std::map<>  コンテナ (map)

#include "Object.h"
#include "Camera.hpp"


int main() {
  AppEnv env(WIDTH, HEIGHT, false, false);

  SpriteID focus = SpriteID::Player;   // カメラの注目対象
  bool escape = false;

  sCamera camera;

  // カメラ初期化
  {
    const Vec2f InitData = Vec2f(0, 0);
    const Vec2f BgSize = Vec2f(BackGround_W, BackGround_H);
    camera.initCamera(InitData, BgSize);
  }

  Object bg(SpriteID::BackGround);
  Object player(SpriteID::Player);
  Object enemy(SpriteID::Enemy);

  while (env.isOpen() && !escape) {
    escape = env.isPushKey(ESCAPE);

    // カメラの注目対象を切り替える
    if (env.isPushKey(SPACE)) {
      focus = focus == SpriteID::Player
        ? SpriteID::Enemy
        : SpriteID::Player;
    }

    // カメラが注目しているオブジェクトを操作
    focus == SpriteID::Player
      ? player.update(env)
      : enemy.update(env);

    // 注目対象の座標を取得
    {
      const Vec2f ObjectPos = focus == SpriteID::Player
        ? player.getPos()
        : enemy.getPos();
      camera.updateCamera(ObjectPos);
    }

    env.begin();
    bg.draw(camera.pos_);
    player.draw(camera.pos_);
    enemy.draw(camera.pos_);
    env.end();
  }
}
