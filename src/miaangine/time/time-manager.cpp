#include "time-manager.hpp"

namespace mia
{
    TimeManager::TimeManager():
        _currentTicks(SDL_GetPerformanceCounter()),
        _lastFrameTicks(SDL_GetPerformanceCounter()),
        _elapseTicks(SDL_GetPerformanceCounter()),
        _elapseTime(0),
        _FPS(0),
        _currentTime(0),
        _stepCount(0)
    {}

    TimeManager::~TimeManager()
    {
        
    }

    void TimeManager::Step()
    {
        _currentTicks = SDL_GetPerformanceCounter();
        _elapseTime = static_cast<double>(_currentTicks - _lastFrameTicks) / static_cast<double>(SDL_GetPerformanceFrequency());
        _lastFrameTicks = _currentTicks;

        if (_elapseTime != 0)
        {
            _FPS = 1.0 / _elapseTime;
        }
        else 
        {
            _FPS = 0.0;
        }

        _currentTime += _elapseTime;

        _stepCount++;
    }
}