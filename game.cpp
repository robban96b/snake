#include "game.h"

Game::Game() {
    window = NULL;
    isRunning = true;
    ball = NULL;
    x = 400;
    y = 300;
    toggle = 0;
    t = 0;
}

int Game::onExecute() {
    if (onInit() == false) {
        return -1;
    }
    if (loadContent() == false) {
        return -1;
    }

    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            onEvent(&event);
        }

        onLoop();
        onRender();
    }

    cleanup();

    return 0;
}

void Game::cleanup() {
    SDL_DestroyTexture(ball);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    Game theGame;

    return theGame.onExecute();
}
