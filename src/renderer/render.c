#include <stdio.h>
#include <stdlib.h>
#include "../../include/render.h"
#include "../../include/config.h"

#define GRID_WIDTH 40
#define GRID_HEIGHT 20

void renderFrame(int birdX, int birdY, Pipe pipes[], int score) {
    char grid[GRID_HEIGHT][GRID_WIDTH];
    for (int row = 0; row < GRID_HEIGHT; row++)
        for (int col = 0; col < GRID_WIDTH; col++)
            grid[row][col] = ' ';

    for (int col = 0; col < GRID_WIDTH; col++) {
        grid[0][col] = '-';
        grid[GRID_HEIGHT - 1][col] = '-';
    }

    int scaledBirdX = (birdX * GRID_WIDTH) / SCREEN_WIDTH;
    int scaledBirdY = (birdY * GRID_HEIGHT) / SCREEN_HEIGHT;
    if (scaledBirdY > 0 && scaledBirdY < GRID_HEIGHT - 1 &&
        scaledBirdX >= 0 && scaledBirdX < GRID_WIDTH) {
        grid[scaledBirdY][scaledBirdX] = 'O';
    }

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
    printf("Collect coins, escape the vulture!\n\n");
    printf("Press any key to start...\n");
}

void renderGameOver(int finalScore) {
    system("cls");
    printf("=====================================\n");
    printf("              GAME OVER\n");
    printf("=====================================\n\n");
    printf("Final Score: %d\n", finalScore);
    printf("Press any key to exit...\n");
}