#pragma once
#include "paddle.h"

class CpuPaddle: public Paddle 
{
    public: 

    CpuPaddle(); 
    void Update(int ball_y); 

};