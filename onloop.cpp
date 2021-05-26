#include "game.h"

void Game::onLoop() {
    if (t == 1 and toggle == 0) {
        toggle = 1;
        t = 0;
    }
    if (t == 1 and toggle == 1) {
        toggle = 0;
        t = 0;
    }
}
