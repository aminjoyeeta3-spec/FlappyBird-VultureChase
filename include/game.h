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
    GAME_OVER,
    COUNTDOWN
} GameState;

typedef struct
{
    int score;
    int running;
    int speed;
    int currentGapHeight;  
    int scoreSaved; 
    GameState state;
    float spawnTimer;
    float difficultyTimer;
    float speedTimer;
    float coinTimer;
    float countdownTimer;
} Game;

extern Game game;
extern Vulture vulture;

void initializeGame(void);

void updateGame(void);

#endif