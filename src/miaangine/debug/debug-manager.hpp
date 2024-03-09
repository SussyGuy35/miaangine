#ifndef _MIA_DEBUG_MANAGER_HPP
#define _MIA_DEBUG_MANAGER_HPP

#include "log-system.hpp"

namespace mia
{
    class DebugManager
    {
        private:
            static DebugManager *__instance;
        public:
            static DebugManager* Instance() 
            {
                if (!__instance) __instance = new DebugManager(); 
                return __instance;
            }

            DebugManager(const DebugManager&) = delete;
            void operator=(const DebugManager&) = delete;

        private:
            DebugManager();

        public:
            ~DebugManager();

        private:
            LogSystem *logs; 

        public:
            void Log(const char *format, ...);
    };
}

#endif