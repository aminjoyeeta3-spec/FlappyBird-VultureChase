#include<raylib.h>
#include<render.h>
#include<game.h>
#include<config.h>

int main(void)
{

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");

    SetTargetFPS(60);

    initializeGame();
    initRenderer();

    while(!WindowShouldClose())
    {
        updateGame();
        renderFrame();

    }

    CloseWindow();

    return 0;
}