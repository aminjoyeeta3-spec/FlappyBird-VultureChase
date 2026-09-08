#include "../../include/collision.h"
#include "../../include/config.h"
#include "raylib.h"

CollisionType checkBoundaryCollision(float birdY) {
    if (birdY - BIRD_RADIUS <= 0) {
        return COLLISION_BOUNDARY;
    }
    
    if (birdY + BIRD_RADIUS >= SCREEN_HEIGHT) {
        return COLLISION_BOUNDARY;
    }
    
    return COLLISION_NONE;
}

CollisionType checkPipeCollision(float birdX, float birdY, Pipe pipes[]) {
    Vector2 birdCenter = { birdX, birdY };

    for (int i = 0; i < MAX_PIPES; i++) {
        if (pipes[i].active == 1) {
            Rectangle topPipe = {
                pipes[i].x, 
                0,
                PIPE_WIDTH,
                 pipes[i].gapY
            };
            Rectangle bottomPipe = {
                pipes[i].x,
                pipes[i].gapY + pipes[i].gapHeight,
                PIPE_WIDTH,
                SCREEN_HEIGHT - (pipes[i].gapY + pipes[i].gapHeight)
            };
            if (CheckCollisionCircleRec(birdCenter, BIRD_RADIUS, topPipe) || CheckCollisionCircleRec(birdCenter, BIRD_RADIUS, bottomPipe)) {
                return COLLISION_PIPE;
            }
        }
    }
    return COLLISION_NONE;
}

CollisionType checkVultureCollision(float birdX, float birdY, Vulture *vulture)
{
    if (!isVultureActive(vulture)) {
        return COLLISION_NONE;
    }
    Vector2 birdCenter = { birdX, birdY };
    Rectangle vultureRect = {
        vulture->x, vulture->y, vulture->width, vulture->height
    };
    if (CheckCollisionCircleRec(birdCenter, BIRD_RADIUS, vultureRect)) {
        return COLLISION_VULTURE;
    }
    return COLLISION_NONE;
}
