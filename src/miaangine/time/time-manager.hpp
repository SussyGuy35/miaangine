#ifndef _MIA_TIME_HPP
#define _MIA_TIME_HPP

#include <SDL.h>

namespace mia
{
    class TimeManager
    {
    private:
        static TimeManager *__instance;
    public:
        static TimeManager* Instance() 
        {
            if (!__instance) __instance = new TimeManager(); 
            return __instance;
        }

        TimeManager(const TimeManager&) = delete;
        void operator=(const TimeManager&) = delete;

    private:
        TimeManager();
        ~TimeManager();

    private:
        uint64_t _currentTicks, _lastFrameTicks, _elapseTicks;

        double _elapseTime;
        float _FPS;
        double _currentTime;
        uint64_t _stepCount;

    public:
        const double &elapseTime = _elapseTime;
        const float &FPS = _FPS; 
        const double &time = _currentTime;
        const uint64_t &stepCount = _stepCount;

        void Step();
    };
}

#endif