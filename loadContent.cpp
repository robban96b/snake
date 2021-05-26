#include "game.h"

bool Game::loadContent() {
    int w = 0, h = 0;
    ball = IMG_LoadTexture(renderer, "resources/face.png");
    SDL_QueryTexture(ball, NULL, NULL, &w, &h);
    rectball.x = x;
    rectball.y = y;
    rectball.w = w;
    rectball.h = h;

    return 1;
}
