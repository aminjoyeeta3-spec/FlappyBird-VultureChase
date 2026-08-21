#include "raylib.h"
#include "../../include/bird.h"
#include "../../include/render.h"

Texture2D birdTexture;

void initRenderer(void){
    birdTexture = LoadTexture("Picture/Assets/bird.png");
}

void renderFrame(void){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(birdTexture, bird.x, bird.y, WHITE);
    EndDrawing();
}