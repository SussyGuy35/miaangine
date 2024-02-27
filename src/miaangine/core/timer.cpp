#include "timer.hpp"

namespace mia
{
    Timer::Timer() :
        _startTicks(0),
        _elapseTicks(0),
        _lastFrameTicks(0),
        _timeStep(0.0)
    {}

    void Timer::TimerCalculate()
    {
        uint32_t currentTicks = SDL_GetTicks();
        _elapseTicks = currentTicks - _startTicks;
        _timeStep = 1.0 * (currentTicks - _lastFrameTicks) / 1000.0;
        _lastFrameTicks = currentTicks;

        _frameCount++;
        if (_elapseTicks >= 1000) 
        {
            _FPS = static_cast<float>(_frameCount) / (_elapseTicks / 1000.0f);
            _frameCount = 0;
            _startTicks = currentTicks;
        }
    }
}