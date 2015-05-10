
#include <sstream>
#include "../FrameWork/gadget.h"
#include "score.h"


cScore::cScore() :
m_font("res/mplus12r.ttf"),
m_STR("score: "),
m_POS(-WIDTH / 2 + 4, HEIGHT / 2 - 40) {

  scoreInit();
}


void cScore::start() {
  m_font.size(fontSize::SMALL);
}


void cScore::scoreAdd() {
  ++m_score;
}


void cScore::scoreInit() {
  m_score = 0;
}


void cScore::draw() {
  std::ostringstream score;
  score << m_STR.c_str() << m_score;

  m_font.draw(score.str(), m_POS, Color::white);
}
