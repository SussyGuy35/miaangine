#ifndef _MIA_LOG_SYSTEM_HPP
#define _MIA_LOG_SYSTEM_HPP

#include <stdarg.h>
#include <string>

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

    public:
        void Log(const char *format, ...);

    private:
        void AppendMiaEntityLogToStr(char type, void *data, char *out, int &len);
        void VirtualLog(char *out, size_t size, const char *format, ...);
    };
}

#endif