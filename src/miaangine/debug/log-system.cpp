#include "log-system.hpp"

#include <SDL.h>
#include <cstring>

#include "time/time-manager.hpp"

#include "util/math.hpp"
#include "object/game-object.hpp"

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
        char str[1024] = "";
        int len = 0;
     
        char tlog[512];
        UpdateNormalLog(tlog, sizeof(tlog), "%.3f - %llu > ", TimeManager::Instance()->time, TimeManager::Instance()->stepCount);
        strcat(str, tlog);
        len += strlen(tlog);
        
        va_list args; 
        va_start(args, format);

        for (int i = 0; format[i] != '\0'; ++i) 
        {
            if (format[i] == '%' && format[i + 1] == '^')
            {
                ++i; ++i;
                char type = format[i];

                void *data = va_arg(args, void*);
                ProcessEntityLog(format[i], data, str, len);
            }
            else 
            {
                str[len++] = format[i];
            }
        }
        str[len] = '\0';

        SDL_Log("%s", str);

        va_end(args);
    }

    void LogSystem::ProcessEntityLog(char type, void *data, char *str, int &len)
    {
        switch (type)
        {
        case 'v':
            {
                Vector2 *entity = const_cast<Vector2*>( static_cast<const Vector2*>(data) );

                char out[512];
                UpdateNormalLog(out, sizeof(out), "(%.2f, %.2f)[Vector2]", entity->x, entity->y);
            
                strcat(str, out);
                len += strlen(out);
            }
            break;

        case 'o':
            {
                GameObject *entity = const_cast<GameObject*>( static_cast<const GameObject*>(data) );

                char out[512];
                UpdateNormalLog(out, sizeof(out), "%s[GameObject]", (entity->name).c_str());
            
                strcat(str, out);
                len += strlen(out);
            }
            break;
        
        default:
            break;
        }
    }

    void LogSystem::UpdateNormalLog(char *out, size_t size, const char *format, ...)
    {
        va_list args;
        va_start(args, format);
        vsnprintf(out, size, format, args);
        va_end(args);
    }
}