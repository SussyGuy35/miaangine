#include "debug-manager.hpp"

#include <SDL.h>
#include <cstring>

#include "time/time-manager.hpp"

#include "util/math.hpp"
#include "object/game-object.hpp"

namespace mia
{
    DebugManager *DebugManager::__instance = nullptr;

    DebugManager::DebugManager()
    {

    }

    DebugManager::~DebugManager()
    {
        __instance = nullptr;
    }

    void DebugManager::Log(const char *format, ...)
    {
        
    }
}