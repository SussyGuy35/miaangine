#include "log-system.hpp"

#include "util/math.hpp"

namespace mia
{
    LogSystem *LogSystem::__instance = nullptr;

    LogSystem::LogSystem()
    {

    }

    LogSystem::~LogSystem()
    {
        __instance = nullptr;
    }

    void LogSystem::Log(const char *format, ...)
    {
        std::string outFormat;

        va_list args;
        va_start(args, format);

        for (int i = 0; format[i] != '\0'; ++i) 
        {
            if (format[i] == '%' && format[i + 1] == '^')
            {
                ++i; ++i;
                char type = format[i];
                if (type == '\0') break;

                ProcessEntityLog(type, args, outFormat);
            }

            outFormat.push_back(format[i]);
        }
        
        va_end(args);
    }

    void LogSystem::ProcessEntityLog(char type, va_list &args, std::string &output)
    {
        switch (type)
        {
        case 'v':
            // Vector2 entity = va_arg(args, void*);

            break;
        
        default:
            break;
        }
    }
}