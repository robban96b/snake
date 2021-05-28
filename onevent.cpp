#include "game.h"

// http://wiki.libsdl.org/SDL_EventType

void Game::onEvent(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_UP:
            // y++;
            newWantedHeadDirection = Direction::up;
            break;
        case SDLK_DOWN:
            // y--;
            newWantedHeadDirection = Direction::down;
            break;
        case SDLK_RIGHT:
            // x++;
            newWantedHeadDirection = Direction::right;
            break;
        case SDLK_LEFT:
            // x--;
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
