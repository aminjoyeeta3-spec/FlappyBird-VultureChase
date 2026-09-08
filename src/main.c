#include<raylib.h>
#include<render.h>
#include<game.h>
#include<config.h>
#include<safezone.h>

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    SetTargetFPS(60);

    initializeGame();
    initRenderer();

    while(!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_SPACE))
            jumpBird();

        if (game.state == PLAYING)
        {
            updateGame();
        }
        else if (game.state == GAME_OVER)
        {
            if (IsKeyPressed(KEY_R))
                initializeGame();
        }

        renderFrame();
    }

    CloseWindow();
    return 0;
}