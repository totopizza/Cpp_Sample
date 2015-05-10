
#include "System/environment.h"
#include "System/exec_app.h"


int main() {
  env::get();

  cExecApp app;
  app.startUp();

  while (app.isOpen()) {
    app.update();
    app.draw();
  }
}
