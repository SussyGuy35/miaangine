#include "time.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Time::Time():
        _deltaTime(0),
        _FPS(0),
        _currentTime(0),
        _stepCount(0),
        _currentTicks(SDL_GetPerformanceCounter()),
        _lastFrameTicks(SDL_GetPerformanceCounter()),
        _elapseTicks(SDL_GetPerformanceCounter())
    {}

    Time::~Time()
    {}
#pragma endregion

#pragma region GetSet method
    double Time::deltaTime() const
    {
        return _deltaTime;
    }
    float Time::fps() const
    {
        return _FPS;
    }
    double Time::time() const
    {
        return _currentTime;
    }
    uint64_t Time::stepCount() const
    {
        return _stepCount;
    }
#pragma endregion

#pragma region Public method
    void Time::Step()
    {
        _currentTicks = SDL_GetPerformanceCounter();
        _elapseTicks = _currentTicks - _lastFrameTicks;
        _lastFrameTicks = _currentTicks;

        _deltaTime = static_cast<double>(_elapseTicks) / static_cast<double>(SDL_GetPerformanceFrequency());
        // _deltaTime = 1;

        _currentTime += _deltaTime;

        _stepCount++;

        if (_deltaTime == 0) _FPS = 0;
        else _FPS = 1 / _deltaTime;
    }
#pragma endregion
}