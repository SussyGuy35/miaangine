#ifndef _MIA_TIMER_HPP
#define _MIA_TIMER_HPP

#include <SDL.h>

namespace mia
{
    class Timer
    {
    public:
        Timer();

    private:
        uint32_t _startTicks, _elapseTicks, _lastFrameTicks;

        double _timeStep;

        float _FPS;
        uint32_t _frameCount;

    public:


        void TimerCalculate();

    };
}

#endif