
#include <ctime>   // FIXME: chrono Žg‚¢‚½‚¢
#include "card.h"


cCard::cCard() :
m_SIZE(CARD_W, CARD_H) {

  m_rand.setSeed(u_int(time(nullptr)));
}


void cCard::cardInit() {
}


void cCard::start() {
  cardInit();
}


void cCard::update() {
}


void cCard::draw() {
}
