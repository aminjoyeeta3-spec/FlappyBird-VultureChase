#include <stdio.h>

#include "../include/platform.h"
#include "../include/game.h"
#include "../include/bird.h"
#include "../include/time.h"

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

     

        printf("========== GREED TRAP ==========\n\n");

        printf("Bird Position : %.2f\n", bird.y);

        printf("Bird Velocity : %.2f\n", bird.velocityY);

        printf("Gravity       : %.2f\n", bird.gravity);

        printf("Score         : %d\n", game.score);

        printf("Time          : %.2f\n", gameTime);

        printf("\n");

        printf("SPACE -> Jump\n");

        printf("Q     -> Quit\n");

        sleepMS(1000/FPS);
    }

    clearScreen();

    printf("\n");
    printf("=========== GAME OVER ===========\n");
    printf("Final Score : %d\n", game.score);

    return 0;
}