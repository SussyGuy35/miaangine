#ifndef _MIA_GENERIC_TASKS_HPP
#define _MIA_GENERIC_TASKS_HPP

#include <stdint.h>

#include "util/singleton.hpp"

namespace mia
{
    class Generic : public Singleton<Generic>
    {
    private:
        friend class Singleton<Generic>;
        Generic();

    public:
        int windowWidth, windowHeight;
        bool fullscreenMode;

        void Init(uint32_t width, uint32_t height, bool fullscreen);
        void End();

        void NewFrame();
        void Render();
    };
}

#endif