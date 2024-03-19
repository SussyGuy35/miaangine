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
            _currentTicks(SDL_GetPerformanceCounter()),
            _lastFrameTicks(SDL_GetPerformanceCounter()),
            _elapseTicks(SDL_GetPerformanceCounter()),
            _deltaTime(0),
            _FPS(0),
            _currentTime(0),
            _stepCount(0)
        {}

        ~TimeManager()
        {}

    private:
        uint64_t _currentTicks, _lastFrameTicks, _elapseTicks;

        double _deltaTime;
        float _FPS;
        double _currentTime;
        uint64_t _stepCount;

    public:
        inline const double& deltaTime()
        {
            return _deltaTime;
        }
        inline const float& fps()
        {
            return _FPS;
        }
        inline const double& time()
        {
            return _currentTime;
        }
        inline const uint64_t& stepCount()
        {
            return _stepCount;
        }

        inline void Step()
        {
            _currentTicks = SDL_GetPerformanceCounter();
            _elapseTicks = _currentTicks - _lastFrameTicks;
            _deltaTime = static_cast<double>(_elapseTicks) / static_cast<double>(SDL_GetPerformanceFrequency());
            _lastFrameTicks = _currentTicks;

            if (_deltaTime != 0)
            {
                _FPS = 1.0 / _deltaTime;
            }
            else 
            {
                _FPS = 0.0;
            }

            _currentTime += _deltaTime;

            _stepCount++;
        }
    };
}

#endif