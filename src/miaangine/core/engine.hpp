#ifndef _MIA_ENGINE_HPP
#define _MIA_ENGINE_HPP

#include <memory>

namespace mia
{
    extern int windowWidth, windowHeight;
    extern bool fullscreenMode;

    void Init(uint32_t width, uint32_t height, bool fullscreen);
    void End();

    void NewFrame();
    void Render();
}

#endif