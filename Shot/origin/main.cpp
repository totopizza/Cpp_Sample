
#include "shot.h"
#include <list>


int main() {
  AppEnv env(WIDTH, HEIGHT, false, false);

  bool escape = false;
  std::list<cShot> shot;

  while (env.isOpen() && !escape) {
    escape = env.isPushKey(ESCAPE);

    if (env.isPushButton(Mouse::LEFT)) {
      shot.push_back(cShot());
    }

    // FIXME: 多分、もっといい書き方があると思う
    // ありました
    auto itr = shot.begin();
    while (itr != shot.end()) {
      itr->update();
      itr->destroy() ? itr = shot.erase(itr) : ++itr;
    }
    /*
    auto begin = shot.begin();
    auto end   = shot.end();
    for (auto it = begin; it != end; ++it) {
      it->update();

      if (it->destroy()) {
        shot.erase(it);
        break;
      }
    }
    */

    env.setupDraw();
    for (auto& it : shot) { it.draw(); }
    env.update();
  }
}
