
#pragma once
#include "../common.h"
#include <memory>


class cEnvironment {

  // TIPS: Ç±ÇÃÉNÉâÉXÇÕêÈåæÇµÇ»Ç¢
  cEnvironment() = delete;

  static std::unique_ptr<AppEnv> app_;
  static std::unique_ptr<Media> se_;
  static Vec2f mouse_pos_;

public:
  static void execApplication();

  static void mousePosUpdate();
  static void sePlay();

  static void setupDraw();
  static void update();

  static bool isOpen();

  static bool leftClick();
  static bool rightClick();
  static bool rectOnMouse(const Vec2f& pos,
                          const Vec2f& size);

  static int score;
};

typedef cEnvironment  env;
