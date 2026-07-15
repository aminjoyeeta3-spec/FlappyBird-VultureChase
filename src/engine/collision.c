#include "../../include/collision.h"
#include "../../include/config.h"

CollisionType checkBoundaryCollision(int birdY, int birdHeight) {
    
    if (birdY <= 0) {
        return COLLISION_BOUNDARY;
    }
    
    if ((birdY + birdHeight) >= SCREEN_HEIGHT) {
        return COLLISION_BOUNDARY;
    }
    
    return COLLISION_NONE;
}

CollisionType checkPipeCollision(int birdX, int birdY, int birdWidth, int birdHeight, Pipe pipes[]) {

    int birdLeft = birdX;
    int birdRight = birdX + birdWidth;
    int birdTop = birdY;
    int birdBottom = birdY + birdHeight;

    for (int i = 0; i < MAX_PIPES; i++) {
        if (pipes[i].active == 1) {
            
            int pipeLeft = pipes[i].x;
            int pipeRight = pipes[i].x + PIPE_WIDTH;
            
            int gapTop = pipes[i].gapY;
            int gapBottom = pipes[i].gapY + pipes[i].gapHeight;

            if (birdRight > pipeLeft && birdLeft < pipeRight) {
                
                if (birdTop < gapTop || birdBottom > gapBottom) {
                    return COLLISION_PIPE; // Instant Game Over trigger
                }
            }
        }
    }
    
    return COLLISION_NONE;
}
