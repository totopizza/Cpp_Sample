
#include "environment.h"


AppEnv* env::get() {
  static AppEnv s_env(WIDTH, HEIGHT, false, false);
  return &s_env;
}
