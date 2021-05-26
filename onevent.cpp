#include "game.h"

// http://wiki.libsdl.org/SDL_EventType

void Game::onEvent(SDL_Event *event) {
    if (event->type == SDL_QUIT) {
        isRunning = false;
    }
    if (toggle == 0) {
        if (event->type == SDL_KEYDOWN) {
            switch (event->key.keysym.sym) {
            case SDLK_UP:
                y++;
                break;
            case SDLK_DOWN:
                y--;
                break;
            case SDLK_RIGHT:
                x++;
                break;
            case SDLK_LEFT:
                x--;
                break;
            }
        }
    }
    if (event->type == SDL_KEYDOWN) {
        switch (event->key.keysym.sym) {
        case SDLK_SPACE:
            t = 1;
            break;
        case SDLK_ESCAPE:
            isRunning = false;
            break;
        }
    }

    if (toggle == 1) {
        if (event->type == SDL_MOUSEMOTION) {
            SDL_GetMouseState(&x, &y);
        }
    }
}
