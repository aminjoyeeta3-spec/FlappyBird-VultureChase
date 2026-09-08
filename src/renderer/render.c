#include<stdio.h>
#include "raylib.h"
#include "../../include/bird.h"
#include "../../include/render.h"
#include "../../include/coin.h"
#include "../../include/game.h"
#include "../../include/pipe.h"
#include "../../include/config.h"
#include "../../include/safezone.h"

Texture2D birdTexture;
Texture2D coinTexture;
Texture2D starTexture;
Texture2D backgroundTexture;

void initRenderer(void){
    birdTexture = LoadTexture("assets/bird.png");
    coinTexture = LoadTexture("assets/coin.png");
    starTexture = LoadTexture("assets/star.png");
    backgroundTexture = LoadTexture("assets/background.png");
}

void renderFrame(void){
    BeginDrawing();

    DrawTexture(backgroundTexture, 0, 0, WHITE);

    DrawTexture(birdTexture, bird.x - BIRD_RADIUS, bird.y - BIRD_RADIUS, WHITE);

    for(int i = 0; i < MAX_PIPES; i++){
    if(pipes[i].active == 1){
        DrawRectangle(pipes[i].x, 0, PIPE_WIDTH, pipes[i].gapY, GREEN);
        DrawRectangle(pipes[i].x, pipes[i].gapY + pipes[i].gapHeight, PIPE_WIDTH, SCREEN_HEIGHT - (pipes[i].gapY + pipes[i].gapHeight), GREEN);
    }
}

    for(int i = 0; i < MAX_COINS; i++){
        if(coins[i].active == 1){
            if(coins[i].type == COIN){
                DrawTexture(coinTexture, coins[i].x, coins[i].y, WHITE);
            } else if(coins[i].type == GEM){
                DrawTexture(starTexture, coins[i].x, coins[i].y, WHITE);
            }
        }
    }

    DrawRectangle(0, safeZone.top, SCREEN_WIDTH, 3, GREEN);
    DrawRectangle(0, safeZone.bottom, SCREEN_WIDTH, 3, GREEN);

    char scoreText[32];
    sprintf(scoreText, "Score: %d", game.score);
    DrawText(scoreText, 10, 10, 20, BLACK);
    EndDrawing();
}

