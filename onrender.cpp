#include "game.h"

void Game::onRender() {
    int w = 0, h = 0;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    rectball.x = x - 16;
    if (toggle == 0) {
        rectball.y = h - y - 16;
    }
    if (toggle == 1) {
        rectball.y = y - 16;
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, ball, NULL, &rectball);
    SDL_RenderPresent(renderer);
}
