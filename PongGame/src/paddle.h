#pragma once

class Paddle
{
    public: 
    float x; 
    float y; 
    float width; 
    float height; 
    int speed; 

    Paddle(); 
    void Draw(); 
    void Update(); 

    protected: 
    void LimitMovement(); 
    
};