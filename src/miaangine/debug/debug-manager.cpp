#include "debug-manager.hpp"

#include <SDL.h>
#include <cstdio>
#include <cstring>

#include "time/time-manager.hpp"

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
        char out[512] = "";

        FormatStr(out, "%.3f - %llu > ", TimeManager::Instance()->time, TimeManager::Instance()->stepCount);

        char str[512];
        va_list args;
        va_start(args, format);
        vsnprintf(str, sizeof(str), format, args);
        va_end(args);

        strcat(out, str);

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, out);
    }

    void DebugManager::Warning(const char *format, ...)
    {
        char out[512] = "";

        FormatStr(out, "%.3f - %llu > ", TimeManager::Instance()->time, TimeManager::Instance()->stepCount);

        char str[512];
        va_list args;
        va_start(args, format);
        vsnprintf(str, sizeof(str), format, args);
        va_end(args);

        strcat(out, str);

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_WARN, out);
    }

    void DebugManager::Error(const char *format, ...)
    {
        char out[512] = "";

        FormatStr(out, "%.3f - %llu > ", TimeManager::Instance()->time, TimeManager::Instance()->stepCount);

        char str[512];
        va_list args;
        va_start(args, format);
        vsnprintf(str, sizeof(str), format, args);
        va_end(args);

        strcat(out, str);

        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, out);
    }

    void DebugManager::FormatStr(char *out, const char *format, ...)
    {
        va_list args;
        va_start(args, format);
        vsnprintf(out, 512, format, args);
        va_end(args);
    }
}