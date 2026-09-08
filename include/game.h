#ifndef GAME_H
#define GAME_H

#include "bird.h"
#include "config.h"
#include "vulture.h"

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
    int currentGapHeight;   
    GameState state;
    float spawnTimer;
    float difficultyTimer;
    float speedTimer;
} Game;

extern Game game;
extern Vulture vulture;

void initializeGame(void);

void updateGame(void);

#endif