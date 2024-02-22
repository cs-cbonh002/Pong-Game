#include "ball.h"
#include <raylib.h>

Ball::Ball()
{
    speed_x = 5;
    speed_y = 5;
    radius = 20;
}

void Ball::Update(int& cpu_score, int& player_score)
{
    x += speed_x;
    y += speed_y;

    if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
        speed_y *= -1;
    }
    if (x + radius >= GetScreenWidth())
    {
        cpu_score++; 
        ResetBall(); 
    }
    
    if (x - radius <= 0)
    {
        player_score++; 
        ResetBall(); 
    }

    
}

void Ball::Draw()
{
    DrawCircle(x, y, radius, WHITE);
}

void Ball::ResetBall()
{
    x = GetScreenWidth() / 2; 
    y = GetScreenHeight() / 2; 

    int speed_choices[2] = {-1, 1}; 
    speed_x *= speed_choices[GetRandomValue(0, 1)]; 
    speed_y *= speed_choices[GetRandomValue(0, 1)]; 
}