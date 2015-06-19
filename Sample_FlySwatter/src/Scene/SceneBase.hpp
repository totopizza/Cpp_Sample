
#pragma once
#include "../Score.hpp"
#include <memory>


namespace common {

enum class SceneName {
  None,

  Title,
  MainGame,
  Result,

  All_Scene,
};


class SceneBase {
public:
  SceneBase(const SceneName o,
            const SceneName n) :
            own_(o), next_(n),
            is_finish_(false), time_(0),
            font_("res/MeiryoConsolas.ttf") {
  }

  virtual void update() {}
  virtual void draw() = 0;

  const SceneName getSceneName() const { return own_; }
  const SceneName getNextScene() const { return next_; }

  const bool isFinish() const { return is_finish_; }

protected:
  SceneName own_;
  SceneName next_;

  bool is_finish_;
  unsigned short time_;

  Font font_;
  Media effect_;
  Texture back_ground_;

  void effectSetup(Media& media,
                   const std::string& path,
                   const float gain) {
    media = Media(path);
    media.gain(gain);
  }

  void textureSetup(Texture& tex,
                    const std::string& path) {
    tex = Texture(path);
  }

  void timeUpdate() {
    time_ = time_ < Fps ? time_ + 1 : 0;
  }

  void drawBackGround() {
    drawTextureBox(-WIDTH / 2, -HEIGHT / 2, WIDTH, HEIGHT,
                   0, 0, 512, 512,
                   back_ground_);
  }
};

}

typedef std::shared_ptr<common::SceneBase>  pScene;
