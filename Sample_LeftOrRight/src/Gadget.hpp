
#pragma once
#include "Common.hpp"


namespace common {

enum FontSize {
  SMALL  = 40,
  MEDIUM = 60,
  LARGE  = 80,
};


class Gadget {
public:
  static Gadget& get() {
    static Gadget s_gadget;
    return s_gadget;
  }

  void drawFrameWindow(const Vec2f& pos,
                       const Vec2f& size,
                       const Color& color) {
    drawFillBox(pos.x(), pos.y(),
                size.x(), size.y(),
                Color::white);

    drawBox(pos.x(), pos.y(),
            size.x(), size.y(),
            LINE_WIDTH, color);
  }

  void drawTimeGauge(const float per) {
    const float POS_X = -WIDTH / 2 + (WIDTH - GAUGE_WIDTH) * 0.5f;
    const float POS_Y = -HEIGHT / 2 + GAUGE_HEIGHT;

    drawFillBox(POS_X, POS_Y,
                GAUGE_WIDTH, GAUGE_HEIGHT,
                Color(0.25f, 0.25f, 0.25f));

    drawFillBox(POS_X, POS_Y,
                GAUGE_WIDTH * per, GAUGE_HEIGHT,
                getGaugeColor(per));
  }

  void scoreDraw() {
    const Vec2f pos(SCORE_POS_X, SCORE_POS_Y);

    std::ostringstream score;
    score << "score: " << score_;

    font_.draw(score.str(), pos, Color::white);
  }

  void scoreAdd() { ++score_; }
  void scoreInit() { score_ = 0; }

private:
  enum {
    LINE_WIDTH = 3,

    GAUGE_WIDTH = (WIDTH / 10) * 9,
    GAUGE_HEIGHT = 40,

    SCORE_POS_X = -WIDTH / 2 + 4,
    SCORE_POS_Y = HEIGHT / 2 - 40,
  };

  Font font_;
  short score_;

  Gadget() : font_("res/mplus12r.ttf") { font_.size(SMALL); }

  Color getGaugeColor(const float per) const {
    return
      per > 0.75f ? Color(0, 1, 0) :
      per > 0.50f ? Color(1, 1, 0) :
      per > 0.25f ? Color(1, 0.5f, 0) :
      Color(1, 0, 0);
  }
};

}

typedef common::Gadget  gadget;
