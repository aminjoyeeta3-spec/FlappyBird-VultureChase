#include<raylib.h>
#include<bird.h>
#include<render.h>

int main(void)
{

    InitWindow(800, 600, "Flappy Bird");

    SetTargetFPS(60);

    initializeBird();
    initRenderer();

    while(!WindowShouldClose())
    {
        float deltaTime = GetFrameTime();
        updateBird(deltaTime);
        renderFrame();

    }

    CloseWindow();

    return 0;
}