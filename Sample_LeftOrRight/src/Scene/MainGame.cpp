
#include "MainGame.h"

using namespace common;


MainGame::MainGame() :
SceneBase(SceneName::MainGame, SceneName::Result),
limit_(Fps * 10) {
  font_.size(SMALL);
  texture_ = Texture("res/card.png");
  rand_.setSeed(u_int(time(nullptr)));
  cardInit();
  gadget::get().scoreInit();
}


void MainGame::update() {
  const auto& Card_L = card_.front().first;
  const auto& Card_R = card_.front().second;
  const Vec2f pos(-WIDTH / 4, 0);
  const Vec2f size(CARD_W, CARD_H);

  const auto on_L = isOnRect(pos - size / 2, size);
  const auto on_R = isOnRect(-pos - size / 2, size);

  const auto high_L = Card_L.num > Card_R.num;
  const auto high_R = Card_L.num < Card_R.num;

  if (App::get().isPushButton(Mouse::LEFT)) {
    if ((on_L && high_L) || (on_R && high_R) ||
        (!high_L && !high_R && (on_L || on_R))) {
      gadget::get().scoreAdd();
    }
    if (on_L || on_R) card_.pop();
    if (card_.size() == 0) cardInit();
  }

  gameFinish();
}


void MainGame::draw() {
  const auto& Card_L = card_.front().first;
  const auto& Card_R = card_.front().second;
  const Vec2f pos(-WIDTH / 4, 0);

  drawCard(Card_L, pos);
  drawCard(Card_R, -pos);

  const auto ratio = static_cast<float>(limit_);
  gadget::get().drawTimeGauge((limit_ - time_) / ratio);
  gadget::get().scoreDraw();
}


void MainGame::cardInit() {
  const float pos_x = common::WIDTH / 4;

  // 初期化テーブルを用意
  std::vector<CardParam> table;
  for (int i = 0; i < CARD_MAX; ++i) {
    const auto pos = i & 2 ? -pos_x : pos_x;
    table.push_back({ i % CARD_NUM, i / CARD_NUM });
  }

  // ランダムに混ぜる
  for (unsigned int i = 0; i < table.size(); ++i) {
    std::swap(table[i], table[rand_(table.size())]);
    std::swap(table[i], table[rand_(table.size())]);
  }

  // ゲームに使える状態にする
  for (auto itr = table.rbegin(); itr != table.rend();) {
    if (table.size() < 2) break;
    auto c1 = *(itr++);
    auto c2 = *(itr++);
    card_.push(std::make_pair(c1, c2));
    table.pop_back();
    table.pop_back();
  }
}


void MainGame::drawCard(const CardParam& card,
                        const Vec2f& pos) {
  const Vec2f size(CARD_W, CARD_H);
  const auto on_rect = common::isOnRect(pos - size / 2, size);
  const auto cut_x = card.num  * size.x();
  const auto cut_y = card.mark * size.y();

  drawTextureBox(pos.x(), pos.y(), size.x(), size.y(),
                 cut_x, cut_y, size.x(), size.y(),
                 texture_, on_rect ? Color::yellow : Color::white,
                 0, Vec2f::Ones(), size / 2);
}


void MainGame::gameFinish() {
  ++time_;
  if (time_ < limit_) return;

  is_finish_ = true;
}
