#include "../../include/bird.h"


Bird bird;
void initializeBird(void)
{
    bird.x = 120.0f;

    bird.y = 360.0f;

    bird.velocityY = 0.0f;

    bird.gravity = 950.0f;

    bird.jumpForce = -450.0f;

    bird.alive = 1;
}


void updateBird(float deltaTime)
{
    bird.velocityY += bird.gravity * deltaTime;
    bird.y += bird.velocityY * deltaTime;
}

void jumpBird(void)
{
    bird.velocityY = bird.jumpForce;
}