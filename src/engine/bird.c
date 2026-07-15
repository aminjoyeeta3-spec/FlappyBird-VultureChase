#include "../../include/bird.h"



void initializeBird(void)
{
    bird.x = 15.0f;

    bird.y = 12.0f;

    bird.velocityY = 0.0f;

    bird.gravity = 30.0f;

    bird.jumpForce = -12.0f;

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