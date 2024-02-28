#ifndef _MIA_DEBUG_MANAGER_HPP
#define _MIA_DEBUG_MANAGER_HPP

#include <SDL.h>

namespace mia
{
    class DebugManager
    {
    public:
        DebugManager();

    public:
        void Init();
        static void CustomLogOutput(void *userdata, int category, SDL_LogPriority priority, const char *message);
    };
}

#endif