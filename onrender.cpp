#include "game.h"

void Game::onRender() {
    int w = 0, h = 0;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    SDL_RenderClear(renderer);
    SDL_Rect rectangle = {
        snakeBodyComponents[0].xCoordinateInGrid * SQUARE_SIZE + SQUARE_SIZE,
        snakeBodyComponents[0].yCoordinateInGrid * SQUARE_SIZE + SQUARE_SIZE,
        SQUARE_SIZE, SQUARE_SIZE};

    // Render head
    SDL_RenderCopyEx(renderer, headTexture, NULL, &rectangle,
                     static_cast<double>(snakeBodyComponents[0].direction),
                     NULL, SDL_FLIP_NONE);

    // Render rest of body
    for (size_t n = 1; n < snakeBodyComponents.size(); n++) {
        rectangle = {snakeBodyComponents[n].xCoordinateInGrid * SQUARE_SIZE +
                         SQUARE_SIZE,
                     snakeBodyComponents[n].yCoordinateInGrid * SQUARE_SIZE +
                         SQUARE_SIZE,
                     SQUARE_SIZE, SQUARE_SIZE};

        SDL_RenderCopyEx(renderer, bodyTexture, NULL, &rectangle,
                         static_cast<double>(snakeBodyComponents[n].direction),
                         NULL, SDL_FLIP_NONE);
    }

    // Render wall
    for (int y = 0; y < GRID_SIZE_HEIGHT; y++) {
        for (int x = 0; x < GRID_SIZE_WIDTH; x++) {
            if (grid[x][y] == GridObject::wall) {
                rectangle = {x * SQUARE_SIZE + SQUARE_SIZE,
                             y * SQUARE_SIZE + SQUARE_SIZE, SQUARE_SIZE,
                             SQUARE_SIZE};
                SDL_RenderCopy(renderer, wallTexture, NULL, &rectangle);
            }
        }
    }

    // Render food
    rectangle = {xFoodCoordinateInGrid * SQUARE_SIZE + SQUARE_SIZE,
                 yFoodCoordinateInGrid * SQUARE_SIZE + SQUARE_SIZE, SQUARE_SIZE,
                 SQUARE_SIZE};
    SDL_RenderCopy(renderer, foodTexture, NULL, &rectangle);

    SDL_RenderPresent(renderer);
}
