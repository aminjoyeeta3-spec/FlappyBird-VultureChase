#include<stdio.h>
#include "raylib.h"
#include <math.h>
#include "../../include/bird.h"
#include "../../include/render.h"
#include "../../include/coin.h"
#include "../../include/game.h"
#include "../../include/pipe.h"
#include "../../include/config.h"
#include "../../include/safezone.h"
#include "../../include/vulture.h"

Texture2D birdTexture;
Texture2D coinTexture;
Texture2D starTexture;
Texture2D backgroundTexture;
Texture2D vultureTexture;

void initRenderer(void){
    birdTexture = LoadTexture("assets/bird.png");
    coinTexture = LoadTexture("assets/coin.png");
    starTexture = LoadTexture("assets/star.png");
    backgroundTexture = LoadTexture("assets/background.png");
    vultureTexture = LoadTexture("assets/vulture.png");
}

void renderFrame(void){
    BeginDrawing();

    DrawTexture(backgroundTexture, 0, 0, WHITE);

    DrawTexture(birdTexture, bird.x - BIRD_RADIUS, bird.y - BIRD_RADIUS, WHITE);

    DrawRectangle(0, safeZone.top, SCREEN_WIDTH, 3, WHITE);
    DrawRectangle(0, safeZone.bottom, SCREEN_WIDTH, 3, WHITE);

    for(int i = 0; i < MAX_PIPES; i++){
    if(pipes[i].active == 1){
        DrawRectangle(pipes[i].x, 0, PIPE_WIDTH, pipes[i].gapY, (Color){139, 90, 43, 255});
        DrawRectangle(pipes[i].x, pipes[i].gapY + pipes[i].gapHeight, PIPE_WIDTH, SCREEN_HEIGHT - (pipes[i].gapY + pipes[i].gapHeight), (Color){139, 90, 43, 255});
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

    if(vulture.state == VULTURE_ACTIVE){
        DrawTexture(vultureTexture, vulture.x, vulture.y, WHITE);
    }
    
    if (game.state == COUNTDOWN)
{
    int count = (int)ceil(game.countdownTimer);
    char countText[8];
    sprintf(countText, "%d", count);
    DrawText(countText, SCREEN_WIDTH/2 - 20, SCREEN_HEIGHT/2 - 40, 80, WHITE);
}   

    if (game.state != COUNTDOWN)
{
    char scoreText[32];
    sprintf(scoreText, "Score: %d", game.score);
    DrawText(scoreText, 10, 10, 20, BLACK);
}
    
    if (game.state == GAME_OVER)
{
    DrawText("GAME OVER", 130, 300, 40, MAROON);
    DrawText("Press R to Restart", 150, 350, 20, BLACK);
}

    EndDrawing();
}

