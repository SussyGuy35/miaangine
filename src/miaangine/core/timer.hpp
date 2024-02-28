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
        uint64_t _currentTicks, _lastFrameTicks, _elapseTicks;

        double _elapseTime;
        float _FPS;
        double _currentTime;
        uint64_t _frameCount;

    public:
        const double &elapseTime = _elapseTime;
        const float &FPS = _FPS;
        const uint64_t &frameCount = _frameCount;
        const double &time = _currentTime;

        void Step();

        void Log();
    };
}

#endif