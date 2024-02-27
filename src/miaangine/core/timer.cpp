#include "timer.hpp"

namespace mia
{
    Timer::Timer() :
        _startTicks(0),
        _elapseTicks(0),
        _lastFrameTicks(0),
        _currentTick(SDL_GetTicks()),
        _timeStep(0.0)
    {}

    void Timer::Step()
    {
        _currentTick = SDL_GetTicks();
        _elapseTicks = _currentTick - _startTicks;
        _timeStep = static_cast<double>(_currentTick - _lastFrameTicks) / 1000.0;
        _lastFrameTicks = _currentTick;

        _frameCount++;
        if (_elapseTicks >= 1000) 
        {
            _FPS = static_cast<float>(_frameCount) / (_elapseTicks / 1000.0f);
            _frameCount = 0;
            _startTicks = _currentTick;
        }
    }
}