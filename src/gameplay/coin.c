#include "../../include/coin.h"
#include <stdlib.h>

Coin coins[MAX_COINS];

void initializeCoins(Coin coins[])
{

    for (int i = 0; i < MAX_COINS; i++)
    {

        coins[i].x = 0;

        coins[i].y = 0;

        coins[i].width = 10;

        coins[i].height = 10;

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

            coins[i].y =
                (rand() % (SCREEN_HEIGHT - 2 * GAP_MARGIN))
                + GAP_MARGIN;

            coins[i].width = 10;

            coins[i].height = 10;

            coins[i].type = type;

            if (type == COIN)
            {

                coins[i].value = 10;

            }
            else
            {

                coins[i].value = 50;

            }

            break;

        }

    }

}

int collectCoin(
    Coin coins[],
    int birdX,
    int birdY,
    int birdWidth,
    int birdHeight)
{

    int totalScore = 0;

    for (int i = 0; i < MAX_COINS; i++)
    {

        if (coins[i].active == 1)
        {

            if (
                birdX < coins[i].x + coins[i].width &&
                birdX + birdWidth > coins[i].x &&
                birdY < coins[i].y + coins[i].height &&
                birdY + birdHeight > coins[i].y
            )
            {

                totalScore += coins[i].value;

                coins[i].active = 0;

            }

        }

    }

    return totalScore;

}