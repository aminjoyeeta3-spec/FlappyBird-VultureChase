#ifndef COLLISION_H
#define COLLISION_H

#include "pipe.h"
#include "config.h"


typedef enum {
    COLLISION_NONE = 0,
    COLLISION_BOUNDARY = 1,
    COLLISION_PIPE = 2
} CollisionType;


CollisionType checkBoundaryCollision(int birdY, int birdHeight);


CollisionType checkPipeCollision(int birdX, int birdY, int birdWidth, int birdHeight, Pipe pipes[]);

#endif