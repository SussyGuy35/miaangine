#include "window-manager.hpp"

namespace mia
{
    WindowManager *WindowManager::__instance = nullptr;

    WindowManager::WindowManager():
        _width(0),
        _height(0),
        _fullscreen(0)
    {}

    WindowManager::~WindowManager()
    {
        __instance = nullptr;
    }

    void WindowManager::ChangeWindow(int width, int height)
    {
        _width = width;
        _height = height;
    }

    void WindowManager::ChangeFullscreen(bool state)
    {
        _fullscreen = state;
    }
}