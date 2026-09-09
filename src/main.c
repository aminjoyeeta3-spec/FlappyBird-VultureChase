#include <raylib.h>
#include <render.h>
#include <game.h>
#include <config.h>
#include <safezone.h>
#include <score.h>
#include <time.h>

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Flappy Bird");
    SetTargetFPS(60);

    initializeGame();
    initRenderer();

    while (!WindowShouldClose())
{
    updateTimer();

    if (IsKeyPressed(KEY_SPACE))
        jumpBird();

    if (game.state == PLAYING)
    {
        updateGame();
    }
    else if (game.state == COUNTDOWN)
    {
        game.countdownTimer -= deltaTime;
        if (game.countdownTimer <= 0.0f)
        {
            game.state = PLAYING;
        }
    }
    else if (game.state == GAME_OVER)
    {
        if (!game.scoreSaved)
        {
            saveScore(game.score);
            game.scoreSaved = 1;
        }

        if (IsKeyPressed(KEY_R))
            initializeGame();
    }

    renderFrame();
}

    CloseWindow();
    return 0;
}