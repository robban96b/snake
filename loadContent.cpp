#include "game.h"

bool Game::loadContent() {
    int wHead = 0, hHead = 0;
    int wBody = 0, hBody = 0;
    head = IMG_LoadTexture(renderer, "resources/face.png");
    body = IMG_LoadTexture(renderer, "resources/body.png");
    SDL_QueryTexture(head, NULL, NULL, &wHead, &hHead);
    SDL_QueryTexture(body, NULL, NULL, &wBody, &hBody);

    rectHead.x = snakePositions[0].x;
    rectHead.y = snakePositions[0].y;
    rectHead.w = SQUARE_SIZE;
    rectHead.h = SQUARE_SIZE;

    rectBody.x = snakePositions[1].x;
    rectBody.y = snakePositions[1].y;
    rectBody.w = SQUARE_SIZE;
    rectBody.h = SQUARE_SIZE;

    return 1;
}
