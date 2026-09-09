#include "../../include/vulture.h"
#include "../../include/safezone.h"

void initVulture(Vulture *vulture)
{
    vulture->state  = VULTURE_INACTIVE;
    vulture->timer  = 0.0f;
    vulture->width  = VULTURE_WIDTH;
    vulture->height = VULTURE_HEIGHT;
    vulture->x = -100;
    vulture->y = -100;
}

void activateVulture(Vulture *vulture, int birdX, int birdY)
{
    if (vulture->state == VULTURE_ACTIVE)
    {
        return;
    }

    vulture->state = VULTURE_ACTIVE;
    vulture->timer = VULTURE_STRIKE_TIME;
    vulture->x = birdX - VULTURE_X_OFFSET;

    if (birdY < safeZone.top)
    {
        vulture->y = safeZone.top - VULTURE_OFFSET - vulture->height;
        if (vulture->y < 0)
        {
            vulture->y = 0;
        }
    }
    else
    {
        vulture->y = safeZone.bottom + VULTURE_OFFSET;
        if (vulture->y + vulture->height > SCREEN_HEIGHT)
        {
            vulture->y = SCREEN_HEIGHT - vulture->height;
        }
    }
}

void updateVulture(Vulture *vulture, float deltaTime, int birdX, int birdY)
{
    if (vulture->state != VULTURE_ACTIVE) return;
    
        vulture->timer -= deltaTime;
        if (vulture->timer < 0.0f)
        {
            vulture->timer = 0.0f;
        }
    
    int targetY = birdY - vulture->height / 2;

    int dx = birdX - vulture->x;
    int stepX = (int)(VULTURE_CHASE_SPEED_X * deltaTime);
    if (dx > stepX)
    {
        vulture->x += stepX;
    }
    else if (dx < -stepX)
    {
        vulture->x -= stepX;
    }
    else
    {
        vulture->x = birdX;
    }

    int dy = targetY - vulture->y;
    int stepY = (int)(VULTURE_CHASE_SPEED_Y * deltaTime);
    if (dy > stepY)
        {
        vulture->y += stepY;
        }
    else if (dy < -stepY)
    {
        vulture->y -= stepY;
    }
    else
    {
        vulture->y = targetY;
    }

}

void deactivateVulture(Vulture *vulture)
{
    vulture->state = VULTURE_INACTIVE;
    vulture->timer = 0.0f;
    vulture->x = -100;
    vulture->y = -100;
}

int isVultureActive(Vulture *vulture)
{
    return vulture->state == VULTURE_ACTIVE;
}

int isVultureTimeUp(Vulture *vulture)
{
    return vulture->state == VULTURE_ACTIVE && vulture->timer <= 0.0f;
}