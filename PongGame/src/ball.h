#pragma once

class Ball
{
public:
    Ball();
    void Update(int& cpu_score, int& player_score);
    void Draw();
    void ResetBall(); 

public:
    float x;
    float y;
    int speed_x;
    int speed_y;
    int radius;
};