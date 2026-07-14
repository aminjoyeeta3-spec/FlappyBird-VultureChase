#include "../../include/game.h"
#include "../../include/time.h"
#include "../../include/bird.h"
#include "../../include/collision.h"

Game game;




void initializeGame(void)
{
    game.score = 0;

    game.running = 1;

    game.speed = 1;

    game.state = PLAYING;

    initializeBird();

    initializeTimer();
}




void updateGame(void)
{
    updateTimer();

    updateBird(deltaTime);

    if(checkCollision())
    {
        game.running = 0;

        game.state = GAME_OVER;
    }
}