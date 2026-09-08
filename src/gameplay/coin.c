#include "../../include/coin.h"
#include "../../include/safezone.h"
#include <stdlib.h>
#include "raylib.h"

Coin coins[MAX_COINS];

void initializeCoins(Coin coins[])
{
    for (int i = 0; i < MAX_COINS; i++)
    {
        coins[i].x = 0;
        coins[i].y = 0;
        coins[i].width = 20;
        coins[i].height = 20;
        coins[i].active = 0;
        coins[i].value = 0;
        coins[i].type = COIN;
    }
}

void updateCoins(Coin coins[], int currentSpeed)
{
    for (int i = 0; i < MAX_COINS; i++)
    {
        if (coins[i].active == 1)
        {
            coins[i].x -= currentSpeed;

            if (coins[i].x < -coins[i].width)
            {
                coins[i].active = 0;
            }
        }
    }
}

void spawnCoin(Coin coins[], CoinType type)
{
    for (int i = 0; i < MAX_COINS; i++)
    {
        if (coins[i].active == 0)
        {
            coins[i].active = 1;

            coins[i].x = SCREEN_WIDTH;

            coins[i].width = 20;
            coins[i].height = 20;

            coins[i].type = type;

            if (type == COIN)
            {
                coins[i].y = safeZone.top + (rand() % (safeZone.bottom - safeZone.top - coins[i].height));
                coins[i].value = 10;
            }
            else
            {
                if (rand() % 2 == 0)
                {
                    int range = safeZone.top - coins[i].height;
                    if (range < 1) range = 1;
                    coins[i].y = rand() % range;
                }
                else
                {
                int range = SCREEN_HEIGHT - safeZone.bottom - coins[i].height;
                if (range < 1) range = 1;
               
                coins[i].y = safeZone.bottom + (rand() % range);
                }
                coins[i].value = 50;
            }

            break;
        }
    }
}

int collectCoin(
    Coin coins[],
    float birdX,
    float birdY,
    float birdRadius)
{
    int totalScore = 0;

    for (int i = 0; i < MAX_COINS; i++)
    {
        if (coins[i].active == 1)
        {
            Rectangle coinRect =
            {
                coins[i].x,
                coins[i].y,
                coins[i].width,
                coins[i].height
            };

            if (CheckCollisionCircleRec(
                    (Vector2){birdX, birdY},
                    birdRadius,
                    coinRect))
            {
                totalScore += coins[i].value;
                coins[i].active = 0;
            }
        }
    }

    return totalScore;
}