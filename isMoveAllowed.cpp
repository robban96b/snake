#include "game.h"

bool Game::isMoveAllowed() { //
    switch (grid[snakeBodyComponents[0].xCoordinateInGrid]
                [snakeBodyComponents[0].xCoordinateInGrid]) {
    case GridObject::food:
        break;
    case GridObject::wall:
        break;
    case GridObject::snake:
        break;
    case GridObject::nothing:
        break;
    }

    return true;
}