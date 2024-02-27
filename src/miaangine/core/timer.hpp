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
        uint32_t _currentTick;

        double _timeStep;

        float _FPS;
        uint32_t _frameCount;

    public:
        const uint32_t &currentTick = _currentTick;
        const double &timeStep = _timeStep;
        const float &FPS = _FPS;

        void Step();

    };
}

#endif