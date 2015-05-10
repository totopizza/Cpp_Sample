
#pragma once
#include "scene.hpp"


class cMainGame : public cScene {

  double m_game_time;
  const std::string m_STR;

  const Vec2f m_POS;

  // FIXME: ˆ——‚¿‚É‘Î‰‚Å‚«‚È‚¢
  enum {
    PLAY_TIME = FPS * 10,
    GAUGE_H = 30,
  };

  void spriteInit();

  Color setGaugeColor(const float);

public:

  cMainGame();

  void update();
  void draw();

  SceneState getScene() const;
  std::shared_ptr<cScene> nextScene() const;
};
