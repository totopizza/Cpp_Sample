
#include "gadget.h"


cGadget::cGadget() :
m_font("res/mplus12r.ttf") {
}


cGadget* cGadget::draw() {
  static cGadget s_gadget;
  return &s_gadget;
}


void cGadget::window(const Vec2f& pos,
                     const Vec2f& size,
                     const Color& color) {

  drawFillBox(pos.x(), pos.y(),
              size.x(), size.y(),
              Color::white);

  drawBox(pos.x(), pos.y(),
          size.x(), size.y(),
          LINE_WIDTH, color);
}


void cGadget::timeGauge(const float per) {
  const float POS_X = -WIDTH / 2 + (WIDTH - GAUGE_WIDTH) * 0.5f;
  const float POS_Y = -HEIGHT / 2 + GAUGE_HEIGHT;

  drawFillBox(POS_X, POS_Y,
              GAUGE_WIDTH, GAUGE_HEIGHT,
              Color(0.25f, 0.25f, 0.25f));

  drawFillBox(POS_X, POS_Y,
              GAUGE_WIDTH * per, GAUGE_HEIGHT,
              setGaugeColor(per));
}


Font* cGadget::font() {
  return &m_font;
}


Color cGadget::setGaugeColor(const float per) const {
  return
    per > 0.75f ? Color(0, 1, 0) :
    per > 0.50f ? Color(1, 1, 0) :
    per > 0.25f ? Color(1, 0.5f, 0) :
    Color(1, 0, 0);
}
