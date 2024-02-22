#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "cpuPaddle.h"


using namespace std; 

int player_score = 0; 
int cpu_score = 0; 

Ball ball; 
Paddle player; 
CpuPaddle cpu; 


int main()
{
    cout << "Starting the game" << endl; 
    const int screen_width = 1280; 
    const int screen_height = 800; 
    InitWindow(screen_width, screen_height, "My Pong Game!");
    SetTargetFPS(60); 

    ball.x = screen_width / 2; 
    ball.y = screen_height / 2; 

    player.width = 25; 
    player.height = 120; 
    player.x = screen_width - player.width - 10; 
    player.y = screen_height / 2 - player.height / 2; 
    player.speed = 6; 

    cpu.width = 25; 
    cpu.height = 120; 
    cpu.x = 10; 
    cpu.y = screen_height / 2 - cpu.height / 2; 
    cpu.speed = 6; 

    while (WindowShouldClose() == false)
    {
        BeginDrawing(); 

        // Updating
        ball.Update(cpu_score, player_score); 
        player.Update(); 
        cpu.Update(ball.y); 

        // Checking for collisions
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}))
        {
            ball.speed_x += -1; 
        }
        if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{cpu.x, cpu.y, cpu.width, cpu.height}))
        {
            ball.speed_x += -1; 
        }

        // Drawuing
        ClearBackground(BLACK); 
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE); 
        ball.Draw(); 
        cpu.Draw(); 
        player.Draw(); 
        DrawText(TextFormat("%i", cpu_score), screen_width / 4 - 20, 20, 80, WHITE); 
        DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 80, WHITE); 

        EndDrawing(); 
    }

    CloseWindow(); 

    return 0;
}