#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"

const int SQUARE_SIZE = 20;
const int WINDOW_SIZE_WIDTH = 1000;
const int WINDOW_SIZE_HEIGHT = 600;
enum class Direction { up, down, left, right };

struct Pose {
    int x;
    int y;
    Direction direction;
};

inline std::ostream &operator<<(std::ostream &os, const Direction &d) {
    switch (d) {
    case Direction::up:
        os << "Up";
    case Direction::down:
        os << "Down";
    case Direction::left:
        os << "Left";
    case Direction::right:
        os << "Right";
    }
    return os;
}

class Game {
  private:
    bool isRunning;
    bool gameIsPaused;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    SDL_Texture *head;
    SDL_Rect rectHead;

    SDL_Texture *body;
    SDL_Rect rectBody;

    Direction newWantedHeadDirection;
    std::vector<Pose> snakePositions;

  public:
    Game();
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
