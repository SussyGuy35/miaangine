#ifndef _MIA_LOG_SYSTEM_HPP
#define _MIA_LOG_SYSTEM_HPP

#include <stdarg.h>

#include "util/singleton.hpp"

namespace mia
{
    class DebugManager : public Singleton<DebugManager>
    {
    private:
        friend class Singleton<DebugManager>;
        DebugManager();
        ~DebugManager();

    public:
        void Log(const char *format, ...);
        void Warning(const char *format, ...);
        void Error(const char *format, ...);

        void FormatStr(char *out, const char *format, ...);
    };
}

#endif