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
    game.currentGapHeight = PIPE_GAP_HEIGHT_START;
    game.spawnTimer = 0.0f;
    game.speedTimer = 0.0f;
    game.difficultyTimer = 0.0f;


    initializeBird();
    initializeTimer();

    initializePipes(pipes);
}


void updateGame(void)
{
    updateTimer();
    updateBird(deltaTime);
    updatePipes(pipes, game.speed);

    
    game.difficultyTimer += deltaTime;
    if (game.difficultyTimer >= 2) {
        if (game.currentGapHeight > PIPE_GAP_HEIGHT_MIN) {
            game.currentGapHeight -= 2;
        }
        game.difficultyTimer = 0.0f;
    }

    if(checkBoundaryCollision(bird.y) != COLLISION_NONE)
    {
        bird.alive = 0;
        game.running = 0;
        game.state = GAME_OVER;
        return;
    }

    if(checkPipeCollision(bird.x, bird.y, pipes) != COLLISION_NONE)
    {
        bird.alive = 0;
        game.running = 0;
        game.state = GAME_OVER;
        return;
    }

    
    game.spawnTimer += deltaTime;
    if(game.spawnTimer >= 2.0f)
    {
        spawnPipe(pipes, game.currentGapHeight);
        game.spawnTimer = 0.0f;
    }

    
    game.speedTimer += deltaTime;
    if (game.speedTimer >= 2.5 && game.speed < 8) {
        game.speed++;
        game.speedTimer = 0.0f;
    }
}