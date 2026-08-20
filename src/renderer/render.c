#include <stdio.h>
#include <stdlib.h>
#include "../../include/render.h"
#include "../../include/config.h"

#define GRID_WIDTH 40
#define GRID_HEIGHT 20

void renderFrame(Bird bird, Pipe pipes[], int score) {
    char grid[GRID_HEIGHT][GRID_WIDTH];

    // blank grid
    for (int row = 0; row < GRID_HEIGHT; row++)
        for (int col = 0; col < GRID_WIDTH; col++)
            grid[row][col] = ' ';

    // sky/ground borders
    for (int col = 0; col < GRID_WIDTH; col++) {
        grid[0][col] = '-';
        grid[GRID_HEIGHT - 1][col] = '-';
    }

    // bird.x/y are small floats (0-ish to ~20s based on initializeBird), scale to grid
    int scaledBirdX = (int)((bird.x / SCREEN_WIDTH) * GRID_WIDTH);
    int scaledBirdY = (int)((bird.y / SCREEN_HEIGHT) * GRID_HEIGHT);
    if (scaledBirdY > 0 && scaledBirdY < GRID_HEIGHT - 1 &&
        scaledBirdX >= 0 && scaledBirdX < GRID_WIDTH) {
        grid[scaledBirdY][scaledBirdX] = 'O';
    }

    // pipes
    for (int i = 0; i < MAX_PIPES; i++) {
        if (!pipes[i].active) continue;

        int scaledPipeX = (pipes[i].x * GRID_WIDTH) / SCREEN_WIDTH;
        int scaledGapY = (pipes[i].gapY * GRID_HEIGHT) / SCREEN_HEIGHT;
        int scaledGapHeight = (pipes[i].gapHeight * GRID_HEIGHT) / SCREEN_HEIGHT;
        if (scaledGapHeight < 1) scaledGapHeight = 1;
        if (scaledPipeX < 0 || scaledPipeX >= GRID_WIDTH) continue;

        for (int row = 1; row < GRID_HEIGHT - 1; row++) {
            if (row >= scaledGapY && row < scaledGapY + scaledGapHeight) continue;
            grid[row][scaledPipeX] = '|';
        }
    }

    system("cls");
    for (int row = 0; row < GRID_HEIGHT; row++) {
        for (int col = 0; col < GRID_WIDTH; col++)
            putchar(grid[row][col]);
        putchar('\n');
    }
    printf("Score: %d\n", score);
}

void renderMenu(void) {
    system("cls");
    printf("=====================================\n");
    printf("       FLAPPY BIRD: VULTURE CHASE\n");
    printf("=====================================\n\n");
    printf("Press SPACE to flap and avoid pipes.\n");
    printf("Press any key to start...\n");
}

void renderGameOver(int finalScore) {
    system("cls");
    printf("=====================================\n");
    printf("              GAME OVER\n");
    printf("=====================================\n\n");
    printf("Final Score: %d\n", finalScore);
}