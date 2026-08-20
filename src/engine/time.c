
#include "../../include/time.h"
#include "raylib.h"

float deltaTime = 0.0f;

float gameTime = 0.0f;





void initializeTimer(void)
{
    gameTime = 0;
}




void updateTimer(void)
{
    deltaTime = GetFrameTime();
    gameTime += deltaTime;
}