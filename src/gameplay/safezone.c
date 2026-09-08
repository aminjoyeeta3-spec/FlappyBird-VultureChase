#include "../../include/safezone.h"

SafeZone safeZone;

void initializeSafeZone(void)
{
    safeZone.top = SCREEN_HEIGHT / 4;
    safeZone.bottom = (SCREEN_HEIGHT * 3) / 4;
}

int isBirdInSafeZone(int birdY)
{
    if (birdY >= safeZone.top && birdY <= safeZone.bottom)
    {
        return 1;
    }

    return 0;
}