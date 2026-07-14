#ifndef PIPE_H
#define PIPE_H

#define MAX_PIPES 5

typedef struct
{
    int x;
    int gapY;
    int gapHeight;
    int active;
} Pipe;

void initializePipes(Pipe pipes[]);
void updatePipes(Pipe pipes[]);
void spawnPipe(Pipe pipes[]);

#endif