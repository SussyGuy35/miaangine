#include "generic-task.hpp"

#include "engine-components.hpp"

namespace mia
{
    Generic::Generic():
        windowWidth(0),
        windowHeight(0),
        fullscreenMode(0)
    {}

    void Generic::Init(uint32_t width, uint32_t height, bool fullscreen)
    {
        windowWidth = width;
        windowHeight = height;
        fullscreenMode = fullscreen;

        sdlHandle.Init(windowWidth, windowHeight, fullscreenMode);

        SDL_Log("**MIAANGINE**\n");

        input.SetupKeyBind();
    }

    void Generic::End()
    {
        sdlHandle.Clear();
    }

    void Generic::NewFrame()
    {
        event.onEnterNewFrame->NotifyListeners();

        time.Step();
        input.Update();

        event.primaryUpdate->NotifyListeners();

        physics.Step(time.elapseTime);
    }

    void Generic::Render()
    {
        renderer.Render(sdlHandle.renderer);
    }
}