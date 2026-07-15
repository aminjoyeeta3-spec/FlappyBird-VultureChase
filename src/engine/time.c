#include "../../include/time.h"

#include <time.h>



float deltaTime = 0.0f;

float gameTime = 0.0f;

static clock_t previousFrame;




void initializeTimer(void)
{
    previousFrame = clock();
}




void updateTimer(void)
{
    clock_t currentFrame = clock();

    deltaTime =
        (float)(currentFrame - previousFrame)/ CLOCKS_PER_SEC;

    gameTime += deltaTime;

    previousFrame = currentFrame;
}