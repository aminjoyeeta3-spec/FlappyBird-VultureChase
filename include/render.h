#ifndef RENDER_H
#define RENDER_H

#include "bird.h"
#include "pipe.h"

void renderFrame(Bird bird, Pipe pipes[], int score);
void renderMenu(void);
void renderGameOver(int finalScore);

#endif