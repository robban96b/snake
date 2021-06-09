#include "game.h"

bool Game::loadContent() {

    // need int reference for width and height for SDL_QueryTexture but we won't
    // save value since we override with SQUARE_SIZE later
    int zero = 0;

    headTexture = IMG_LoadTexture(renderer, "resources/face.png");
    bodyTexture = IMG_LoadTexture(renderer, "resources/body.png");
    wallTexture = IMG_LoadTexture(renderer, "resources/wall.png");
    foodTexture = IMG_LoadTexture(renderer, "resources/food.png");
    SDL_QueryTexture(headTexture, NULL, NULL, &zero, &zero);
    SDL_QueryTexture(bodyTexture, NULL, NULL, &zero, &zero);
    SDL_QueryTexture(wallTexture, NULL, NULL, &zero, &zero);
    SDL_QueryTexture(foodTexture, NULL, NULL, &zero, &zero);

    return 1;
}
