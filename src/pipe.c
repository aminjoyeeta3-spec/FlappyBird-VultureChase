#include "../include/pipe.h"
#include "../include/config.h"
#include <stdlib.h>

void initializePipes(Pipe pipes[]) {
    for (int i = 0; i < MAX_PIPES; i++) {
        pipes[i].active = 0;
        pipes[i].x = 0;
        pipes[i].gapY = 0;
        pipes[i].gapHeight = 0;
    }
}

void updatePipes(Pipe pipes[], int currentSpeed) {
    for (int i = 0; i < MAX_PIPES; i++) {
        if (pipes[i].active == 1) {
            
            pipes[i].x -= currentSpeed; 
            
            if (pipes[i].x < -PIPE_WIDTH) {
                pipes[i].active = 0;
            }
        }
    }
}

void spawnPipe(Pipe pipes[], int currentGapHeight) {
    for (int i = 0; i < MAX_PIPES; i++) {
        if (pipes[i].active == 0) {
            pipes[i].active = 1;
            pipes[i].x = SCREEN_WIDTH;
            
            int maxGapY = SCREEN_HEIGHT - currentGapHeight - GAP_MARGIN;
            pipes[i].gapY = (rand() % (maxGapY - GAP_MARGIN + 1)) + GAP_MARGIN; 
            
            pipes[i].gapHeight = currentGapHeight;
            
            break; 
        }
    }
}