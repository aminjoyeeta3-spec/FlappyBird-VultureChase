#ifndef VULTURE_H
#define VULTURE_H

#include "config.h"

#define VULTURE_STRIKE_TIME 5.0f

#define VULTURE_WIDTH  60
#define VULTURE_HEIGHT 60

#define VULTURE_OFFSET 30
#define VULTURE_X_OFFSET 100

#define VULTURE_CHASE_SPEED_X 60.0f
#define VULTURE_CHASE_SPEED_Y 90.0f

typedef enum
{
    VULTURE_INACTIVE = 0,
    VULTURE_ACTIVE   = 1
} VultureState;

typedef struct
{
    VultureState state;
    float timer;
    int x;
    int y;
    int width;
    int height;
} Vulture;

void initVulture(Vulture *vulture);

void activateVulture(Vulture *vulture, int birdX, int birdY);

void updateVulture(Vulture *vulture, float deltaTime, int birdX, int birdY);

void deactivateVulture(Vulture *vulture);

int isVultureActive(Vulture *vulture);

int isVultureTimeUp(Vulture *vulture);

#endif