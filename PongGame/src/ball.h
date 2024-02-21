#pragma once

class Ball
{
public:
    Ball();
    void Update();
    void Draw();

public:
    float x;
    float y;
    int speed_x;
    int speed_y;
    int radius;
};