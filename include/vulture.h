#ifndef VULTURE_H
#define VULTURE_H

#include "config.h"


typedef struct {
    int active;
    float timer;
    int x;
    int y;
    int width;
    int height;
} Vulture;


void initVulture(Vulture *vulture);

void activateVulture(Vulture *vulture);

void updateVulture(Vulture *vulture, float deltaTime, int birdX, int birdY);

#endif