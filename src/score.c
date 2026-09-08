#include <stdio.h>
#include "../include/score.h"

void saveScore(int score)
{
    FILE *file = fopen(SCORE_FILE, "a");
    if (file != NULL) {
        fprintf(file, "%d\n", score);
        fclose(file);
    }
}

void printLeaderboard(void)
{
    FILE *file = fopen(SCORE_FILE, "r");
    if (file == NULL) {
        printf("No scores yet.\n");
        return;
    }
    int score;
    while (fscanf(file, "%d", &score) == 1) {
        printf("Score: %d\n", score);
    }
    fclose(file);
}