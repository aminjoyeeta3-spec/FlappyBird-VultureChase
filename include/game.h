#ifndef GAME_H
#define GAME_H

#include "bird.h"

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25

#define FPS 20

typedef enum
{
    MENU,
    PLAYING,
    GAME_OVER
} GameState;

typedef struct
{
    int score;

    int running;

    int speed;

    GameState state;

} Game;

extern Game game;

void initializeGame(void);

void updateGame(void);

#endif