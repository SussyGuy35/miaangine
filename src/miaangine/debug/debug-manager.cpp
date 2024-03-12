#include "debug-manager.hpp"

#include <SDL.h>
#include <cstring>

#include "time/time-manager.hpp"

#include "util/math.hpp"
#include "object/game-object.hpp"

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
        char str[1024] = "";
        int len = 0;
     
        char tlog[512];
        VirtualLog(tlog, sizeof(tlog), "%.3f - %llu > ", TimeManager::Instance()->time, TimeManager::Instance()->stepCount);
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
                AppendMiaEntityLogToStr(format[i], data, str, len);
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

    void DebugManager::AppendMiaEntityLogToStr(char type, void *data, char *out, int &len)
    {
        char entityLog[512];

        switch (type)
        {
        case 'v':
            {
                vector2 *entity = const_cast<vector2*>( static_cast<const vector2*>(data) );

                VirtualLog(entityLog, sizeof(entityLog), "(%.2f, %.2f)[Vector2]", entity->x, entity->y);
            }
            break;

        case 'o':
            {
                GameObject *entity = const_cast<GameObject*>( static_cast<const GameObject*>(data) );

                VirtualLog(entityLog, sizeof(entityLog), "%s[GameObject]", (entity->name).str());
            }
            break;
        
        default:
            break;
        }

        strcat(out, entityLog);
        len += strlen(entityLog);
    }

    void DebugManager::VirtualLog(char *out, size_t size, const char *format, ...)
    {
        va_list args;
        va_start(args, format);
        vsnprintf(out, size, format, args);
        va_end(args);
    }
}