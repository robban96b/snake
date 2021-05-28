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
    Pose head = snakePositions[0];
    Direction newDirection;

    // Calculate new direction for head
    if (newWantedHeadDirection == oppositeDirection(head.direction)) {
        newDirection = head.direction;
    } else {
        newDirection = newWantedHeadDirection;
    }

    // Update snakes positions
    for (int i = snakePositions.size() - 1; i > 0; i--) {
        snakePositions[i] = snakePositions[i - 1];
    }
    snakePositions[1].direction = newDirection;

    switch (newDirection) {
    case Direction::up:
        snakePositions[0].y -= SQUARE_SIZE;
        break;
    case Direction::down:
        snakePositions[0].y += SQUARE_SIZE;
        break;
    case Direction::right:
        snakePositions[0].x += SQUARE_SIZE;
        break;
    case Direction::left:
        snakePositions[0].x -= SQUARE_SIZE;
        break;
    }
    snakePositions[0].direction = newDirection;
}
