#ifndef COLLISION_H
#define COLLISION_H

#include "pipe.h"
#include "config.h"
#include "vulture.h"

typedef enum {
    COLLISION_NONE = 0,
    COLLISION_BOUNDARY = 1,
    COLLISION_PIPE = 2,
    COLLISION_VULTURE = 3
} CollisionType;

CollisionType checkBoundaryCollision(float birdY);

CollisionType checkPipeCollision(float birdX, float birdY, Pipe pipes[]);

CollisionType checkVultureCollision(float birdX, float birdY, Vulture *vulture);

#endif
