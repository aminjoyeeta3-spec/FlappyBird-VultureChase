#ifndef SAFEZONE_H
#define SAFEZONE_H

#include "config.h"

typedef struct
{
    int top;
    int bottom;
} SafeZone;

extern SafeZone safeZone;

void initializeSafeZone(void);

int isBirdInSafeZone(int birdY);

#endif