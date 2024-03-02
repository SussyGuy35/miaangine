#ifndef _MIA_TIME_HPP
#define _MIA_TIME_HPP

#include <SDL.h>

namespace mia
{
    class GlobalTime
    {
    private:
        GlobalTime();

    private:
        static uint64_t _currentTicks, _lastFrameTicks, _elapseTicks;

        static double _elapseTime;
        static float _FPS;
        static uint64_t _frameCount;
        static double _currentTime;

    public:
        static const double &elapseTime;
        static const float &FPS;
        static const uint64_t &frameCount;
        static const double &time;

        static void Step();
    };
}

#endif