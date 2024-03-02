#include "time.hpp"

namespace mia
{
    uint64_t GlobalTime::_currentTicks = SDL_GetPerformanceCounter();
    uint64_t GlobalTime::_lastFrameTicks = SDL_GetPerformanceCounter();
    uint64_t GlobalTime::_elapseTicks = 0;

    double GlobalTime::_elapseTime = 0;
    const double &GlobalTime::elapseTime = GlobalTime::_elapseTime;

    float GlobalTime::_FPS = 0;
    const float &GlobalTime::FPS = GlobalTime::_FPS;

    uint64_t GlobalTime::_frameCount = 0;
    const uint64_t &GlobalTime::elapseTime = GlobalTime::_frameCount;

    double GlobalTime::_currentTime = 0;
    const double &GlobalTime::time = GlobalTime::_currentTime;

    GlobalTime::GlobalTime()
    {}

    void GlobalTime::Step()
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