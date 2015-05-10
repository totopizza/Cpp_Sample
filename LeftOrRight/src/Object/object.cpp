
#include "object.h"


cObject::cObject() {
}


void cObject::start() {
  m_card.start();
  m_score.start();
}


void cObject::update() {
}


void cObject::drawCard() {
  m_card.draw();
}


void cObject::drawScore() {
  m_score.draw();
}
