#ifndef BIRD_H
#define BIRD_H

typedef struct
{
    float x;
    float y;

    float velocityY;

    float gravity;

    float jumpForce;

    int alive;

} Bird;

extern Bird bird;


void initializeBird(void);


void updateBird(float deltaTime);


void jumpBird(void);

#endif