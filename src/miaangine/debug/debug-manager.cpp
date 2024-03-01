#include "debug-manager.hpp"

#include <stdio.h>

namespace mia
{
    DebugManager::DebugManager()
    {}

    void DebugManager::Init()
    {
        SDL_LogSetOutputFunction(CustomLogOutput, nullptr);
    }

    void DebugManager::CustomLogOutput(void *userdata, int category, SDL_LogPriority priority, const char *message)
    {
        printf("%s", message);
        fflush(stdout);
    }
}