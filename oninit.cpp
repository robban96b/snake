#include "game.h"

bool Game::onInit() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        return false;
    }
    // Creates a SDL Window
    if ((window = SDL_CreateWindow("My Snake Game", 500, 200, WINDOW_SIZE_WIDTH,
                                   WINDOW_SIZE_HEIGHT,
                                   SDL_RENDERER_PRESENTVSYNC)) == NULL) {
        return false;
    }
    // SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }

    Pose head = {WINDOW_SIZE_WIDTH / 2, WINDOW_SIZE_HEIGHT / 2,
                 Direction::right};
    Pose body = {WINDOW_SIZE_WIDTH / 2 - SQUARE_SIZE, WINDOW_SIZE_HEIGHT / 2,
                 Direction::right};

    snakePositions = {head, body};

    gameIsPaused = true;
    newWantedHeadDirection = Direction::right;
    return true;
}
