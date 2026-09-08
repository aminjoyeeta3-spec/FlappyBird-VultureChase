#include "../../include/bird.h"
#include "../../include/config.h"

Bird bird;

void initializeBird(void)
{
    bird.x = 120.0f;
    bird.y = 360.0f;
    bird.velocityY = 0.0f;
    bird.gravity = 950.0f;
    bird.jumpForce = -450.0f;
    bird.alive = 1;
    bird.flapCount = 0;
    bird.panicTimer = 0.0f;
    bird.isPanicking = 0;
}

void updateBird(float deltaTime)
{
    bird.isPanicking = 0;
    bird.velocityY += bird.gravity * deltaTime;
    bird.y += bird.velocityY * deltaTime;
    bird.panicTimer += deltaTime;
    if (bird.flapCount >= PANIC_FLAP_LIMIT && bird.panicTimer < PANIC_TIME_WINDOW) {
        bird.flapCount = 0;
        bird.panicTimer = 0;
        bird.isPanicking = 1;
    }
    
}

void jumpBird(void)
{
    bird.velocityY = bird.jumpForce;
    bird.flapCount++;
}