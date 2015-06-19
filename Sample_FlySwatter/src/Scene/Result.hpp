
#pragma once
#include "SceneBase.hpp"


namespace common {

class Result : public SceneBase {
public:
  Result() :
    SceneBase(SceneName::Result, SceneName::Title),
    efc_time_(0) {

    font_.size(common::FontSize);
    effectSetup(effect_, "res/end.wav", 0.3f);
    textureSetup(back_ground_, "res/title_bg.png");

    effect_.play();
    Score::get().countPushBack();
    Score::get().rankingSort();
    Score::get().scoreSave();
  }

  void update() {
    timeUpdate();
    if (effectPlay()) { ++efc_time_; return; }

    is_finish_ = App::get().isPushButton(Mouse::LEFT);
  }

  void draw() {
    drawBackGround();
    effectPlay() ? drawFinish() : drawResult();
  }

private:
  short efc_time_;

  const bool effectPlay() const { return efc_time_ < Fps * 2; }

  void drawFinish() {
    const std::string finish("しゅうりょー ");
    const Vec2f pos = -font_.drawSize(finish) / 2;
    font_.draw(finish, pos, Color::white);
  }

  void drawResult() {
    Vec2f pos;

    const std::string logo("はえたたけた？ ");
    pos = -font_.drawSize(logo) / 2;
    pos.y() += common::HEIGHT / 4;
    font_.draw(logo, pos, Color::white);

    const std::string title("左クリックでタイトル ");
    pos = -font_.drawSize(title) / 2;
    pos.y() -= common::HEIGHT / 8;
    font_.draw(title, pos, Color::white);

    const std::string finish("右クリックで終了 ");
    pos = -font_.drawSize(finish) / 2;
    pos.y() -= (common::HEIGHT / 8 + 60);
    font_.draw(finish, pos, Color::white);

    Score::get().drawCurrentScore();
    Score::get().drawRankingScore();

    if (!Score::get().highScoreUpdate()) return;

    const std::string rank_in("ハイスコア更新！ ");
    pos = -font_.drawSize(rank_in) / 2;
    pos.y() += FontSize;
    font_.draw(rank_in, pos, Color::cyan);
  }
};

}
