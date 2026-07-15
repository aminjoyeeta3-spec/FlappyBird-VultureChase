#ifndef GAME_H
#define GAME_H

#include "bird.h"
#include "config.h"

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