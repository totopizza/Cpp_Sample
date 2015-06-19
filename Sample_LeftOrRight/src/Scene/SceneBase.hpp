
#pragma once
#include "../Gadget.hpp"
#include <memory>


enum class SceneName {
  None,

  Title,
  MainGame,
  Result,

  All_Scene,
};


class SceneBase {
public:
  virtual void update() {}
  virtual void draw() {}

  const SceneName getSceneName() const { return own_; }
  const SceneName getNextScene() const { return next_; }

  const bool isFinish() const { return is_finish_; }

protected:
  SceneName own_;
  SceneName next_;

  bool is_finish_;

  short blink_;
  short time_;

  Font font_;

  SceneBase(const SceneName o,
            const SceneName n) :
            own_(o), next_(n),
            is_finish_(false),
            blink_(0), time_(0),
            font_("res/mplus12r.ttf") {}
};

typedef std::shared_ptr<SceneBase>  pScene;
