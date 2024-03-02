#include "time.hpp"

namespace mia
{
    uint64_t Time::_currentTicks = SDL_GetPerformanceCounter();
    uint64_t Time::_lastFrameTicks = SDL_GetPerformanceCounter();
    uint64_t Time::_elapseTicks = 0;

    double Time::_elapseTime = 0;
    const double &Time::elapseTime = Time::_elapseTime;

    float Time::_FPS = 0;
    const float &Time::FPS = Time::_FPS;

    uint64_t Time::_frameCount = 0;
    const uint64_t &Time::frameCount = Time::_frameCount;

    double Time::_currentTime = 0;
    const double &Time::time = Time::_currentTime;

    Time::Time()
    {}

    void Time::Step()
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

        _frameCount++;
    }
}