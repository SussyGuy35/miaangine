#ifndef _MIA_TIME_HPP
#define _MIA_TIME_HPP

#include "common.hpp"

namespace mia
{
    class Time : public Singleton<Time>
    {
    private:
        friend class Singleton<Time>;
        Time();
        ~Time();

    private:
        double _deltaTime;
        float _FPS;
        double _currentTime;
        uint64_t _stepCount;

        // Variable to solve attributes
        uint64_t _currentTicks, _lastFrameTicks, _elapseTicks;
        uint32_t _FPSFrameCount; double _FPSClockCount;

    public:
        double deltaTime() const;
        float fps() const;
        double time() const;
        uint64_t stepCount() const;

        void Step();
    };
}

#endif