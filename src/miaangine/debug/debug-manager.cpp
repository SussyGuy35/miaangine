#include "debug-manager.hpp"

namespace mia
{
    DebugManager *DebugManager::__instance = nullptr;

    DebugManager::DebugManager():
        logs(LogSystem::Instance())
    {}

    DebugManager::~DebugManager()
    {
        __instance = nullptr;
        
        delete(logs);
    }

    void DebugManager::Log(const char *format, ...)
    {
        
    }
}