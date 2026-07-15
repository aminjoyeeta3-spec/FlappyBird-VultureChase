#include "../../include/game.h"
#include "../../include/time.h"
#include "../../include/bird.h"
#include "../../include/collision.h"
#include "../../include/pipe.h"

Game game;

void initializeGame(void)
{
    game.score = 0;
    game.running = 1;
    game.speed = 2;
    game.state = PLAYING;

    initializeBird();
    initializeTimer();

    initializePipes(pipes);
}


void updateGame(void)
{
    updateTimer();

  
    updateBird(deltaTime);

  
    updatePipes(pipes, game.speed);

    
    if(checkBoundaryCollision((int)bird.y, BIRD_HEIGHT)!= COLLISION_NONE)
    {
        bird.alive = 0;
        game.running = 0;
        game.state = GAME_OVER;
        return;
    }

    
    if(checkPipeCollision(
        (int)bird.x,
        (int)bird.y,
        BIRD_WIDTH,
        BIRD_HEIGHT,pipes)!= COLLISION_NONE)
    {
        bird.alive = 0;
        game.running = 0;
        game.state = GAME_OVER;
        return;
    }


    static float spawnTimer = 0.0f;

    spawnTimer += deltaTime;

    if(spawnTimer >= 2.0f)
    {
        spawnPipe(pipes, 8);

        spawnTimer = 0.0f;
    }

    if(game.speed < 8)
    {
        if(gameTime > game.speed * 10)
        {
            game.speed++;
        }
    }
}