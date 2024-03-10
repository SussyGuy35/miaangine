#include "window-util.hpp"

namespace mia
{
    WindowUtilities *WindowUtilities::__instance = nullptr;

    WindowUtilities::WindowUtilities()
    {}

    WindowUtilities::~WindowUtilities()
    {
        __instance = nullptr;
    }
}