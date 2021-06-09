#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"

const int SQUARE_SIZE = 40;
const int WINDOW_SIZE_WIDTH = 1000;
const int WINDOW_SIZE_HEIGHT = 600;
const int GRID_SIZE_WIDTH = WINDOW_SIZE_WIDTH / SQUARE_SIZE - 2;
const int GRID_SIZE_HEIGHT = WINDOW_SIZE_HEIGHT / SQUARE_SIZE - 2;
const int INIT_SNAKE_LENGTH = 5;

enum class Direction { up = 0, down = 180, left = 270, right = 90 };
enum class GridObject { snake = -1, wall = -2, nothing = 0, food = 1 };

struct SnakeBodyComponent {
    int xCoordinateInGrid;
    int yCoordinateInGrid;
    Direction direction;
};

class Game {
  private:
    bool isRunning;
    bool gameIsPaused;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_Texture *headTexture;
    SDL_Texture *bodyTexture;
    SDL_Texture *wallTexture;
    SDL_Texture *foodTexture;

    int xFoodCoordinateInGrid;
    int yFoodCoordinateInGrid;

    GridObject grid[GRID_SIZE_WIDTH][GRID_SIZE_HEIGHT];
    Direction newWantedHeadDirection;
    std::vector<SnakeBodyComponent> snakeBodyComponents;

  public:
    Game();
    bool updateFood();
    void initSnake();
    void printGridAnalytic();
    void printGridGraphic();
    bool isMoveAllowed();
    void ticTime();
    int onExecute();
    bool onInit();
    bool loadContent();
    void onEvent(SDL_Event *event);
    void onLoop();
    void onRender();
    void cleanup();
};

#endif // GAME_H_INCLUDED
