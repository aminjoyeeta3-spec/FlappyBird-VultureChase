#ifndef PIPE_H
#define PIPE_H

#include "config.h"

typedef struct
{
    int x;
    int gapY;
    int gapHeight;
    int active;
} Pipe;

void initializePipes(Pipe pipes[]);
void updatePipes(Pipe pipes[], int currentSpeed);
void spawnPipe(Pipe pipes[], int currentGapHeight);

#endif
