#ifndef PIPE_H
#define PIPE_H

#include "config.h"

typedef struct
{
    int x;
    int gapY;
    int gapHeight;
    int active;
    int scored;

} Pipe;


extern Pipe pipes[MAX_PIPES];


void initializePipes(Pipe pipes[]);

void updatePipes(Pipe pipes[], int currentSpeed);

void spawnPipe(Pipe pipes[], int currentGapHeight);

int checkPipeScore(Pipe pipes[], float birdX);


#endif
