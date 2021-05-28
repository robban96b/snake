#include "game.h"

Game::Game() {
    window = NULL;
    isRunning = true;
    head = NULL;
    body = NULL;
}

int Game::onExecute() {
    if (onInit() == false) {
        return -1;
    }
    if (loadContent() == false) {
        return -1;
    }
    onRender();
    while (isRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        while (SDL_PollEvent(&event)) {
            onEvent(&event);
        }
        if (!gameIsPaused) {
            ticTime();

            onRender();
        }
    }

    cleanup();

    return 0;
}

void Game::cleanup() {
    SDL_DestroyTexture(head);
    SDL_DestroyTexture(body);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    Game theGame;

    return theGame.onExecute();
}
