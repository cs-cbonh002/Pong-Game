#include <iostream>
#include <raylib.h>
#include "ball.h"
#include "paddle.h"
#include "cpuPaddle.h"


using namespace std; 

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
        ball.Update(); 
        player.Update(); 
        cpu.Update(ball.y); 

        // Drawuing
        ClearBackground(BLACK); 
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE); 
        ball.Draw(); 
        cpu.Draw(); 
        player.Draw(); 

        EndDrawing(); 
    }

    CloseWindow(); 

    return 0;
}