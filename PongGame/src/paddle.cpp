#include "paddle.h"
#include <raylib.h>

Paddle::Paddle()
{

}

void Paddle::Draw()
{
    DrawRectangle(x, y, width, height, WHITE); 
}

void Paddle::Update()
{
    if (IsKeyDown(KEY_UP))
    {
        y = y - speed; 
    }
    if (IsKeyDown(KEY_DOWN))
    {
        y = y + speed; 
    }

    LimitMovement(); 
}

void Paddle::LimitMovement()
{
    if (y <= 0)
    {
        y = 0; 
    }
    if (y + height >= GetScreenHeight())
    {
        y = GetScreenHeight() - height; 
    }
}