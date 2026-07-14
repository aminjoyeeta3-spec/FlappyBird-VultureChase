#ifndef RENDER_H
#define RENDER_H

#include "pipe.h"

void renderFrame(int birdX, int birdY, Pipe pipes[], int score);
void renderMenu(void);
void renderGameOver(int finalScore);

#endif