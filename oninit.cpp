#include "game.h"

bool Game::onInit() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        return false;
    }
    // Creates a SDL Window
    if ((window = SDL_CreateWindow("Image Loading", 100, 100, 800, 600,
                                   SDL_WINDOW_RESIZABLE |
                                       SDL_RENDERER_PRESENTVSYNC)) == NULL) {
        return false;
    }
    // SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << SDL_GetError() << std::endl;
        return 1;
    }
    return true;
}
