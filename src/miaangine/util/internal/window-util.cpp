#include "window-util.hpp"

namespace mia
{
    WindowUtilities *WindowUtilities::__instance = nullptr;

    WindowUtilities::WindowUtilities():
        _width(0),
        _height(0),
        _fullscreen(0)
    {}

    WindowUtilities::~WindowUtilities()
    {
        __instance = nullptr;
    }

    void WindowUtilities::ChangeWindow(int width, int height)
    {
        _width = width;
        _height = height;
    }

    void WindowUtilities::ChangeFullscreen(bool state)
    {
        _fullscreen = state;
    }
}