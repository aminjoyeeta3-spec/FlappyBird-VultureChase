#include "../../include/collision.h"
#include "../../include/bird.h"
#include "../../include/game.h"



int checkCollision(void)
{

    if (bird.y >= SCREEN_HEIGHT - 1)
    {
        bird.alive = 0;
        return 1;
    }


    if (bird.y < 0)
    {
        bird.alive = 0;
        return 1;
    }

   

    return 0;
}