#include "engine.hpp"

#include "engine-components.hpp"

int mia::windowWidth = 10;
int mia::windowHeight = 10;
bool mia::fullscreenMode = 0;

void mia::Init(uint32_t width, uint32_t height, bool fullscreen)
{
    windowWidth = width;
    windowHeight = height;
    fullscreenMode = fullscreen;

    sdlHandle.Init(windowWidth, windowHeight, mia::fullscreenMode);

    SDL_Log("**MIAANGINE**\n");

    input.SetupKeyBind();
}

void mia::End()
{
    sdlHandle.Clear();
}

void mia::NewFrame()
{
    event.onEnterNewFrame->NotifyListeners();

    time.Step();
    input.Update();

    event.primaryUpdate->NotifyListeners();

    physics.Step(time.elapseTime);
}

void mia::Render()
{
    mia::renderer.Render(sdlHandle.renderer);
}