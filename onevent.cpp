#include "game.h"

// http://wiki.libsdl.org/SDL_EventType

void Game::onEvent(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_UP:
            newWantedHeadDirection = Direction::up;
            break;
        case SDLK_DOWN:
            newWantedHeadDirection = Direction::down;
            break;
        case SDLK_RIGHT:
            newWantedHeadDirection = Direction::right;
            break;
        case SDLK_LEFT:
            newWantedHeadDirection = Direction::left;
            break;
        }
    }
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_ESCAPE:
            isRunning = false;
            break;

        case SDLK_SPACE:
            gameIsPaused = !gameIsPaused;
            break;
        }
    }
}
