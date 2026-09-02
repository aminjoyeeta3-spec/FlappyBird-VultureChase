#include "raylib.h"
#include "../../include/bird.h"
#include "../../include/render.h"
#include "../../include/coin.h"

Texture2D birdTexture;

void initRenderer(void){
    birdTexture = LoadTexture("assets/bird.png");
}

void renderFrame(void){
    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawTexture(birdTexture, bird.x, bird.y, WHITE);

    for(int i = 0; i < MAX_COINS; i++){
        if(coins[i].active == 1){
            DrawRectangle(coins[i].x, coins[i].y, coins[i].width, coins[i].height, YELLOW);
        }
    }

    EndDrawing();
}