#ifndef VULTURE_H
#define VULTURE_H

#include "config.h"

#define VULTURE_STRIKE_TIME 5.0f

#define VULTURE_WIDTH  40
#define VULTURE_HEIGHT 40

#define VULTURE_OFFSET 30

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

void updateVulture(Vulture *vulture, float deltaTime);

void deactivateVulture(Vulture *vulture);

int isVultureActive(Vulture *vulture);

int isVultureTimeUp(Vulture *vulture);

#endif