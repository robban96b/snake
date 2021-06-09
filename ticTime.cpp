#include "game.h"

Direction oppositeDirection(Direction direction) {
    switch (direction) {
    case Direction::up:
        return Direction::down;
    case Direction::down:
        return Direction::up;
    case Direction::right:
        return Direction::left;
    case Direction::left:
        return Direction::right;
    default:
        return direction; // TODO: fix this
    }
}

void Game::ticTime() {
    Direction newDirection;
    SnakeBodyComponent oldTail = snakeBodyComponents.back();

    // Determine new direction for head
    if (newWantedHeadDirection ==
        oppositeDirection(snakeBodyComponents[0].direction)) {
        newDirection = snakeBodyComponents[0].direction;
    } else {
        newDirection = newWantedHeadDirection;
    }

    // Update snakes positions
    for (int i = snakeBodyComponents.size() - 1; i > 0; i--) {
        snakeBodyComponents[i] = snakeBodyComponents[i - 1];
    }
    snakeBodyComponents[1].direction = newDirection;

    switch (newDirection) {
    case Direction::up:
        snakeBodyComponents[0].yCoordinateInGrid -= 1;
        break;
    case Direction::down:
        snakeBodyComponents[0].yCoordinateInGrid += 1;
        break;
    case Direction::right:
        snakeBodyComponents[0].xCoordinateInGrid += 1;
        break;
    case Direction::left:
        snakeBodyComponents[0].xCoordinateInGrid -= 1;
        break;
    }
    snakeBodyComponents[0].direction = newDirection;

    // Check if collision or food was reached
    GridObject newLocationObject =
        grid[snakeBodyComponents[0].xCoordinateInGrid] //
            [snakeBodyComponents[0].yCoordinateInGrid];

    switch (newLocationObject) {
    case GridObject::nothing:
        grid[oldTail.xCoordinateInGrid][oldTail.yCoordinateInGrid] =
            GridObject::nothing;
        break;
    case GridObject::food:
        snakeBodyComponents.push_back(oldTail);
        if (!updateFood()) {
            gameIsPaused = true;
        }
        break; // don't remove tail
    case GridObject::wall:
        gameIsPaused = true;
        break;
    case GridObject::snake:
        gameIsPaused = true;
    }

    grid[snakeBodyComponents[0].xCoordinateInGrid] // move head
        [snakeBodyComponents[0].yCoordinateInGrid] = GridObject::snake;
}
