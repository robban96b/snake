#include "game.h"

void Game::onRender() {
    int w = 0, h = 0;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    rectHead.x = snakePositions[0].x;
    rectHead.y = snakePositions[0].y;

    rectBody.x = snakePositions[1].x;
    rectBody.y = snakePositions[1].y;

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, head, NULL, &rectHead);
    SDL_RenderCopy(renderer, body, NULL, &rectBody);
    SDL_RenderPresent(renderer);
}
