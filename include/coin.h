#ifndef COIN_H
#define COIN_H

#include "config.h"

#define MAX_COINS 10

typedef enum
{
    COIN,
    GEM
} CoinType;

typedef struct
{
    int x;
    int y;
    int width;
    int height;
    int active;
    int value;
    CoinType type;
} Coin;

extern Coin coins[MAX_COINS];

void initializeCoins(Coin coins[]);

void updateCoins(Coin coins[], int currentSpeed);

void spawnCoin(Coin coins[], CoinType type);

int collectCoin(Coin coins[], int birdX, int birdY, int birdWidth, int birdHeight);

#endif