#include "raylib.h"
#include "../../include/bird.h"
#include "../../include/render.h"
#include "../../include/coin.h"

Texture2D birdTexture;
Texture2D coinTexture;
Texture2D starTexture;

void initRenderer(void){
    birdTexture = LoadTexture("assets/bird.png");
    coinTexture = LoadTexture("assets/coin.png");
    starTexture = LoadTexture("assets/star.png");
}

void renderFrame(void){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexture(birdTexture, bird.x, bird.y, WHITE);

    for(int i = 0; i < MAX_COINS; i++){
        if(coins[i].active == 1){
            if(coins[i].type == COIN){
                DrawTexture(coinTexture, coins[i].x, coins[i].y, WHITE);
            } else if(coins[i].type == GEM){
                DrawTexture(starTexture, coins[i].x, coins[i].y, WHITE);
            }
        }
    }

    EndDrawing();
}