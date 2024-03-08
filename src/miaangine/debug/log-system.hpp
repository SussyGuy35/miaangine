#ifndef _MIA_LOG_SYSTEM_HPP
#define _MIA_LOG_SYSTEM_HPP

#include <stdarg.h>

namespace mia
{
    class LogSystem
    {
    private:
        static LogSystem *__instance;
    public:
        static LogSystem* Instance() 
        {
            if (!__instance) __instance = new LogSystem(); 
            return __instance;
        }

        LogSystem(const LogSystem&) = delete;
        void operator=(const LogSystem&) = delete;

    private:
        LogSystem();

    public:
        void Log(const char *format, ...);

    private:
        void ProcessEntityLog(char type, va_list &args, std::string &output);
    };
}

#endif