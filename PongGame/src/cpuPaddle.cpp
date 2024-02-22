#include <raylib.h>
#include "cpuPaddle.h"

CpuPaddle::CpuPaddle()
{

}

void CpuPaddle::Update(int ball_y)
{
    if (y + height / 2 > ball_y)
    {
        y = y - speed; 
    }
    if (y + height / 2 <= ball_y)
    {
        y = y + speed; 
    }

    LimitMovement(); 
}