#include "ball.h"
#include <raylib.h>

Ball::Ball()
{
    
    speed_x = 7;
    speed_y = 7;
    radius = 20;
}

void Ball::Update()
{
    x += speed_x;
    y += speed_y;

    if (x + radius >= GetScreenWidth() || x - radius <= 0)
        speed_x *= -1;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
        speed_y *= -1;
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}