#ifndef _MIA_TIME_HPP
#define _MIA_TIME_HPP

#include <SDL.h>

#include "util/singleton.hpp"

namespace mia
{
    class TimeManager : public Singleton<TimeManager>
    {
    private:
        friend class Singleton<TimeManager>;
        TimeManager():
            _deltaTime(0),
            _FPS(0),
            _currentTime(0),
            _stepCount(0),
            _currentTicks(SDL_GetPerformanceCounter()),
            _lastFrameTicks(SDL_GetPerformanceCounter()),
            _elapseTicks(SDL_GetPerformanceCounter()),
            _FPSFrameCount(0),
            _FPSClockCount(0)
        {}

        ~TimeManager()
        {}

    private:
        // Attributes
        double _deltaTime;
        float _FPS;
        double _currentTime;
        uint64_t _stepCount;

        // Variable to solve attributes
        uint64_t _currentTicks, _lastFrameTicks, _elapseTicks;
        uint32_t _FPSFrameCount; double _FPSClockCount;

    public:
        // Attributes accessing
        const double& deltaTime() const { return _deltaTime; }
        const float& fps() const { return _FPS; }
        const double& time() const { return _currentTime; }
        const uint64_t& stepCount() const { return _stepCount; }

        // Methods
        void Step()
        {
            _currentTicks = SDL_GetPerformanceCounter();
            _elapseTicks = _currentTicks - _lastFrameTicks;
            _lastFrameTicks = _currentTicks;

            // DeltaTime
            _deltaTime = static_cast<double>(_elapseTicks) / static_cast<double>(SDL_GetPerformanceFrequency());

            // Time
            _currentTime += _deltaTime;

            // Step Count
            _stepCount++;

            // FPS
            _FPSFrameCount++;
            _FPSClockCount += _deltaTime;
            if (_FPSClockCount >= 1.0)
            {
                _FPS = _FPSFrameCount;

                _FPSClockCount = _FPSFrameCount = 0;
            }
        }
    };
}

#endif