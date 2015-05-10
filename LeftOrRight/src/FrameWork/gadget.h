
#pragma once
#include "../common.hpp"


class cGadget {

  cGadget();

  Color setGaugeColor(const float per) const;

  enum {
    LINE_WIDTH = 3,

    GAUGE_WIDTH  = (WIDTH / 10) * 9,
    GAUGE_HEIGHT = 40,
  };

  Font m_font;

public:

  // 描画機能
  // TIPS: アロー( -> )を使って各機能にアクセスする
  static cGadget* draw();

  static enum FontSize {
    SMALL  = 40,
    MEDIUM = 60,
    LARGE  = 80,
  };

  void window(const Vec2f& pos,
              const Vec2f& size,
              const Color& color);

  void timeGauge(const float per);

  Font* font();
};

typedef cGadget            gadget;
typedef cGadget::FontSize  fontSize;
