
#include "resource.h"
#include <string>


cResource::cResource() {
  struct SpriteInfo {
    SpriteID id;
    std::string file_pass;
    Color color;
  };

  const SpriteInfo Table[] = {
    { LargePoint, "res/point_large.png", Color::white },
    { SmallPoint, "res/point_small.png", Color::white },
    { BackGround, "res/background.png",  Color(1, 1, 1, 0.5f) },
  };

  for (auto& it : Table) {
    m_sprite.insert(std::make_pair(it.id, Texture(it.file_pass)));
    m_color.insert(std::make_pair(it.id, it.color));
  }
}


cResource* cResource::get() {
  static cResource s_instance;
  return &s_instance;
}


Texture* cResource::sprite(const SpriteID id) {
  auto& it = m_sprite.find(id);
  return &it->second;
}


Color* cResource::color(const SpriteID id) {
  auto& it = m_color.find(id);
  return &it->second;
}
