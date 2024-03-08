#include "log-system.hpp"

namespace mia
{
    LogSystem *LogSystem::__instance = nullptr;

    LogSystem::LogSystem()
    {

    }

    void LogSystem::Log(const char *format, ...)
    {
        char resultFormat[512];
        int resLength = 0;

        va_list args;
        va_start(args, format);

        
        
        va_end(args);

        OutputLog(resultFormat);
    }

    void LogSystem::OutputLog(const char *textToPrint)
    {
        SDL_Log(textToPrint);
    }
}