#include "game.h"

void Game::printGridAnalytic() {

    for (int y = 0; y < GRID_SIZE_HEIGHT; y++) {
        for (int x = 0; x < GRID_SIZE_WIDTH; x++) {
            std::cout << '[' << static_cast<int>(grid[x][y]) << ']';
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
}
void Game::printGridGraphic() {
    char iconToPrint = ' ';
    for (int y = 0; y < GRID_SIZE_HEIGHT; y++) {
        for (int x = 0; x < GRID_SIZE_WIDTH; x++) {
            switch (grid[x][y]) {
            case GridObject::wall:
                iconToPrint = '#';
                break;
            case GridObject::snake:
                iconToPrint = 'O';
                break;
            case GridObject::food:
                iconToPrint = 'X';
                break;
            // case GridObject::nothing:
            default:
                iconToPrint = ' ';
                break;
            }
            std::cout << iconToPrint;
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
}

Game::Game() {
    window = NULL;
    isRunning = true;
    headTexture = NULL;
    bodyTexture = NULL;
    wallTexture = NULL;
    foodTexture = NULL;
}

int Game::onExecute() {
    if (onInit() == false) {
        return -1;
    }
    if (loadContent() == false) {
        return -1;
    }
    onRender();
    // printGridAnalytic();
    while (isRunning) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        while (SDL_PollEvent(&event)) {
            onEvent(&event);
        }
        if (!gameIsPaused) {
            // if (isMoveAllowed())
            ticTime();

            onRender();
            // printGridAnalytic();
            printGridGraphic();
        }
    }

    cleanup();

    return 0;
}

void Game::cleanup() {
    SDL_DestroyTexture(headTexture);
    SDL_DestroyTexture(bodyTexture);
    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(foodTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[]) {
    Game theGame;

    return theGame.onExecute();
}
