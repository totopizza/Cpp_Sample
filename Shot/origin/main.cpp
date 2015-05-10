
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
    auto begin = shot.begin();
    auto end   = shot.end();
    for (auto it = begin; it != end; ++it) {
      it->update();

      if (it->destroy()) {
        shot.erase(it);
        break;
      }
    }

    env.setupDraw();

    for (auto& it : shot) { it.draw(); }

    env.update();
  }
}
