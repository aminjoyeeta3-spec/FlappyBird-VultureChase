#include "../../include/pipe.h"
#include "../../include/safezone.h"
#include <stdlib.h>

Pipe pipes[MAX_PIPES];

void initializePipes(Pipe pipes[])
{

    for (int i = 0; i < MAX_PIPES; i++)
    {

        pipes[i].active = 0;

        pipes[i].x = 0;

        pipes[i].gapY = 0;

        pipes[i].gapHeight = 0;

        pipes[i].scored = 0;

    }

}

void updatePipes(Pipe pipes[], int currentSpeed)
{

    for (int i = 0; i < MAX_PIPES; i++)
    {

        if (pipes[i].active == 1)
        {

            pipes[i].x -= currentSpeed;

            if (pipes[i].x < -PIPE_WIDTH)
            {

                pipes[i].active = 0;

            }

        }

    }

}

void spawnPipe(Pipe pipes[], int currentGapHeight)
{

    for (int i = 0; i < MAX_PIPES; i++)
    {

        if (pipes[i].active == 0)
        {

            pipes[i].active = 1;

            pipes[i].scored = 0;

            pipes[i].x = SCREEN_WIDTH;

            int minGapY = safeZone.top;
            int maxGapY = safeZone.bottom - currentGapHeight;

            if (maxGapY > minGapY)
            {

                pipes[i].gapY =
                    (rand() % (maxGapY - minGapY + 1))
                    + minGapY;

            }
            else
            {

                pipes[i].gapY = minGapY;

            }

            pipes[i].gapHeight = currentGapHeight;

            break;

        }

    }

}

int checkPipeScore(Pipe pipes[], float birdX)
{
    int points = 0;

    for (int i = 0; i < MAX_PIPES; i++)
    {
        if (pipes[i].active == 1 && !pipes[i].scored)
        {
            if (pipes[i].x + PIPE_WIDTH < birdX)
            {
                pipes[i].scored = 1;
                points += COIN_VALUE;
            }
        }
    }

    return points;
}

int getPipeTopHeight(Pipe pipe)
{
    int height = pipe.gapY - safeZone.top;
    if (height < 0)
    {
        height = 0;
    }
    return height;
}

int getPipeBottomY(Pipe pipe)
{
    return pipe.gapY + pipe.gapHeight;
}

int getPipeBottomHeight(Pipe pipe)
{
    int height = safeZone.bottom - getPipeBottomY(pipe);
    if (height < 0)
    {
        height = 0;
    }
    return height;
}