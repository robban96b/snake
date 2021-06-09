#include "game.h"

bool Game::updateFood() {
    std::vector<int> xCoords;
    std::vector<int> yCoords;

    for (int x = 1; x < GRID_SIZE_WIDTH; x++) {
        xCoords.push_back(x);
    }
    for (int y = 1; y < GRID_SIZE_HEIGHT; y++) {
        yCoords.push_back(y);
    }

    std::random_shuffle(xCoords.begin(), xCoords.end());
    std::random_shuffle(yCoords.begin(), yCoords.end());

    for (int x = 0; x < GRID_SIZE_WIDTH; x++) {
        for (int y = 0; y < GRID_SIZE_HEIGHT; y++) {
            if (grid[xCoords[x]][yCoords[y]] == GridObject::nothing) {
                grid[xCoords[x]][yCoords[y]] = GridObject::food;
                xFoodCoordinateInGrid = xCoords[x];
                yFoodCoordinateInGrid = yCoords[y];
                return true;
            }
        }
    }
    return false; // No empty place for new food
}