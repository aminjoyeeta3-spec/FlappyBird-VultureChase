#include <stdio.h>

#include "../include/platform.h"
#include "../include/game.h"
#include "../include/bird.h"
#include "../include/time.h"
#include "../include/pipe.h"


void renderGame()
{
    printf("========== GREED TRAP ==========\n\n");

    printf("Score : %d\n", game.score);
    printf("Time  : %.2f\n\n", gameTime);


    for(int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for(int x = 0; x < SCREEN_WIDTH; x++)
        {
            int printed = 0;


        
            if(
                x >= bird.x &&
                x <= bird.x + BIRD_WIDTH &&
                y >= bird.y &&
                y <= bird.y + BIRD_HEIGHT
            )
            {
                printf("O");
                printed = 1;
            }


            for(int i = 0; i < MAX_PIPES; i++)
            {
                if(pipes[i].active)
                {

                    if(
                        x >= pipes[i].x &&
                        x <= pipes[i].x + PIPE_WIDTH
                    )
                    {
                        if(y < pipes[i].gapY || y > pipes[i].gapY + pipes[i].gapHeight )
                        {
                            printf("|");
                            printed = 1;
                        }
                    }
                }
            }


            if(!printed)
            {
                printf(" ");
            }
        }

        printf("\n");
    }


    printf("\nSPACE -> Jump");
    printf("\nQ     -> Quit\n");
}



int main()
{

    initializeGame();


    while(game.running)
    {

        clearScreen();


        if(keyPressed())
        {
            char key = getKey();


            if(key == ' ')
            {
                jumpBird();
            }


            if(key == 'q' || key == 'Q')
            {
                game.running = 0;
            }
        }


        updateGame();

        renderGame();

        sleepMS(1000/FPS);

    }



    clearScreen();


    printf("\n");
    printf("=========== GAME OVER ===========\n");
    printf("Final Score : %d\n", game.score);


    return 0;
}
