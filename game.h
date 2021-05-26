#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "includes.h"

class Game {
  private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;

    bool toggle, t;
    int x, y;
    SDL_Texture *ball;
    SDL_Rect rectball;

  public:
    Game();
    int onExecute();
    bool onInit();
    bool loadContent();
    void onEvent(SDL_Event *event);
    void onLoop();
    void onRender();
    void cleanup();
};

#endif // GAME_H_INCLUDED
