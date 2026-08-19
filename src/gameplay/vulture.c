#include "../../include/vulture.h"

void initVulture(Vulture *vulture) {
    vulture->active = 0;
    vulture->timer = 5.0f;
    
    vulture->width = 40;
    vulture->height = 40;
    
    vulture->x = -100;
    vulture->y = -100;
}

void activateVulture(Vulture *vulture) {
    vulture->active = 1;
    vulture->timer = 5.0f;
}

void updateVulture(Vulture *vulture, float deltaTime, int birdX, int birdY) {

    if (vulture->active == 1) {
        
        vulture->timer -= deltaTime;
        
        vulture->x = birdX - 60; 
        
        vulture->y = birdY;
        
        if (vulture->timer <= 0.0f) {
            vulture->active = 0;
            vulture->timer = 0.0f;
            vulture->x = -100; 
        }
    }
}