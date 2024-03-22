#include "debug-manager.hpp"

#include <SDL.h>
#include <cstdio>
#include <cstring>

#include "core/time-manager.hpp"

namespace mia
{
    DebugManager::DebugManager()
    {

    }

    DebugManager::~DebugManager()
    {}
    
    void DebugManager::Message(const char *format, ...)
    {
        char out[512];
        va_list args;
        va_start(args, format);
        vsnprintf(out, sizeof(out), format, args);
        va_end(args);

        printf(out);
    }

    void DebugManager::Log(const char *format, ...)
    {
        char out[512] = "";

        FormatStr(out, "%.3f - %llu > ", TimeManager::Instance().time(), TimeManager::Instance().stepCount());

        char str[512];
        va_list args;
        va_start(args, format);
        vsnprintf(str, sizeof(str), format, args);
        va_end(args);

        strcat(out, str);

        printf("LOG: %s\n", out);
    }

    void DebugManager::Warning(const char *format, ...)
    {
        char out[512] = "";

        FormatStr(out, "%.3f - %llu > ", TimeManager::Instance().time(), TimeManager::Instance().stepCount());

        char str[512];
        va_list args;
        va_start(args, format);
        vsnprintf(str, sizeof(str), format, args);
        va_end(args);

        strcat(out, str);

        printf("WARING: %s\n", out);
    }

    void DebugManager::Error(const char *format, ...)
    {
        char out[512] = "";

        FormatStr(out, "%.3f - %llu > ", TimeManager::Instance().time(), TimeManager::Instance().stepCount());

        char str[512];
        va_list args;
        va_start(args, format);
        vsnprintf(str, sizeof(str), format, args);
        va_end(args);

        strcat(out, str);

        printf("ERROR: %s\n", out);
    }

    void DebugManager::FormatStr(char *out, const char *format, ...)
    {
        va_list args;
        va_start(args, format);
        vsnprintf(out, 512, format, args);
        va_end(args);
    }
}