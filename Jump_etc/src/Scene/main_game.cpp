
#include <string>
#include <fstream>
#include <list>
#include "../FrameWork/resource.h"
#include "../FrameWork/scene_manager.h"
#include "main_game.h"


cMainGame::cMainGame() {
  textRead();
  m_obj.componentInit();
}


void cMainGame::update() {
  m_bg.update();
  m_obj.update();
}


void cMainGame::draw() {
  m_bg.draw();
  m_obj.draw();
}


// NOTICE: 使わない
SceneState cMainGame::getScene() const {
  return SceneState::MainGame;
}


// NOTICE: 使わない
std::shared_ptr<cScene> cMainGame::nextScene() const {
  return std::make_shared<cMainGame>();
}


// NOTICE: 使わない
bool cMainGame::sceneFinish() const {
  return false;
}


// TIPS: リソースの初期化
void cMainGame::textRead() {
  using namespace resource;

  std::vector<std::string> file_pass;

  std::ifstream fstr("res/data.txt");
  {
    int file_hash;
    std::string temp_str;

    fstr >> file_hash;

    for (int index = 0; index < file_hash; ++index) {
      fstr >> temp_str;
      file_pass.emplace_back(temp_str);
    }
  }

  const SpriteInfo Table[] = {
    { SpriteID::BackGround_1, file_pass[BackGround_1], Color::white },
    { SpriteID::BackGround_2, file_pass[BackGround_2], Color::white },
    { SpriteID::Character,    file_pass[Character],    Color::white },
  };

  for (auto& it : Table) {
    res::get()->spriteAppend(it);
  }
}
