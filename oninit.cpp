#include "game.h"

void Game::initSnake() {
    newWantedHeadDirection = Direction::right;
    int xHead = GRID_SIZE_WIDTH / 2;
    int yHead = GRID_SIZE_HEIGHT / 2;

    // Fill grid with "nothing" and walls
    for (int x = 0; x < GRID_SIZE_WIDTH; x++) {
        for (int y = 0; y < GRID_SIZE_HEIGHT; y++) {
            if (x == 0 || x == GRID_SIZE_WIDTH - 1 || y == 0 ||
                y == GRID_SIZE_HEIGHT - 1) {
                grid[x][y] = GridObject::wall;
            } else {

                grid[x][y] = GridObject::nothing;
            }
        }
    }
    // Create snake and insert into grid
    for (int n = 0; n < INIT_SNAKE_LENGTH; n++) {
        // Create snake component
        SnakeBodyComponent bodyComponent = {xHead - n, yHead, Direction::right};
        snakeBodyComponents.push_back(bodyComponent);
        // Insert into grid
        grid[xHead - n][yHead] = GridObject::snake;
    }
}

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

    gameIsPaused = true;
    // numberOfSnakeComponents = 5;
    // newWantedHeadDirection = Direction::right;
    // int xHead = GRID_SIZE_WIDTH / 2;
    // int yHead = GRID_SIZE_HEIGHT / 2;
    initSnake();
    updateFood();

    return true;
}
