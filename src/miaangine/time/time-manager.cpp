#include "time-manager.hpp"

namespace mia
{
    uint64_t TimeManager::_currentTicks = SDL_GetPerformanceCounter();
    uint64_t TimeManager::_lastFrameTicks = SDL_GetPerformanceCounter();
    uint64_t TimeManager::_elapseTicks = 0;

    double TimeManager::_elapseTime = 0;
    const double &TimeManager::elapseTime = TimeManager::_elapseTime;

    float TimeManager::_FPS = 0;
    const float &TimeManager::FPS = TimeManager::_FPS;

    uint64_t TimeManager::_stepCount = 0;
    const uint64_t &TimeManager::stepCount = TimeManager::_stepCount;

    double TimeManager::_currentTime = 0;
    const double &TimeManager::time = TimeManager::_currentTime;

    TimeManager::TimeManager()
    {}

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