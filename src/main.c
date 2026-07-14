#include <stdio.h>
#include "../include/pipe.h"
#include "../include/collision.h"
#include "../include/config.h"

int main() {
    Pipe myPipes[MAX_PIPES];
    initializePipes(myPipes);
    
    // 1. Spawn a pipe and manually place it right in front of our mock bird
    spawnPipe(myPipes, 150); 
    myPipes[0].x = 110; // Pipe is slightly to the right of the bird
    myPipes[0].gapY = 0; // Force the gap to be at the very top to guarantee a collision

    // 2. Set up our Mock Bird
    int birdX = 100;
    int birdY = 200; // Bird is lower than the gap, so it will hit the bottom pipe
    int birdWidth = 30;
    int birdHeight = 30;
    
    printf("--- FLAPPY BIRD LOGIC TEST ---\n\n");
    
    // 3. Run a mini 5-frame game loop
    for (int frame = 1; frame <= 5; frame++) {
        // Move the pipe left by 5 pixels per frame
        updatePipes(myPipes, 5); 
        
        // Check for collisions
        CollisionType hit = checkPipeCollision(birdX, birdY, birdWidth, birdHeight, myPipes);
        
        printf("Frame %d | Pipe X: %3d | Status: ", frame, myPipes[0].x);
        
        if (hit == COLLISION_PIPE) {
            printf("CRASH! (Game Over Triggered)\n");
        } else {
            printf("Safe.\n");
        }
    }
    
    // 4. Test the Boundary Logic (Vulture Trigger)
    printf("\n--- BOUNDARY LOGIC TEST ---\n");
    CollisionType boundaryHit = checkBoundaryCollision(-10, birdHeight); // -10 forces it into the sky
    
    if (boundaryHit == COLLISION_BOUNDARY) {
        printf("SUCCESS: Bird hit the sky! (Vulture Timer Triggered)\n");
    }
    
    return 0;
}