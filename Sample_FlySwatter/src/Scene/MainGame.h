
#pragma once
#include "SceneBase.hpp"


namespace common {

class Main : public SceneBase {
public:
  Main();

  void update();
  void draw();

private:
  enum {
    GameFinishTime = Fps * 10,

    GaugeSize_W = 400,
    GaugeSize_H = 30,
  };

  Texture enemy_;
  Texture enemy_hit_;
  Random rand_;

  int game_time_;

  bool hit_;
  int move_time_;
  int hit_time_;

  bool on_mouse_;
  Vec2f pos_;
  Vec2f offset_;
  const Vec2f size_;

  void enemyInit();
  void enemyMove();

  void dispBackGround();
  void dispLogo();
  void dispEnemy();
  void dispTimeGauge();
  void dispScore();
};

}
