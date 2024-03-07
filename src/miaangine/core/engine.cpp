#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = new mia::SDLHandle();
mia::Events *mia::events = new mia::Events();
mia::PortraitRenderer *mia::portraitRenderer = new mia::PortraitRenderer();
mia::PhysicWorld *mia::physicWorld = new mia::PhysicWorld();

void mia::Init(uint32_t width, uint32_t height, bool fullscreen)
{
    SDL_Log("**MIAANGINE**\n");

    sdlHandle->Init(width, height, fullscreen);
    sdlHandle->Log();

    Input::SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(events);
    delete(portraitRenderer);
    delete(physicWorld);
}

void mia::NewFrame()
{
    events->onEnterNewFrame->NotifyListeners();

    Time::Step();
    Input::Update();

    events->primaryUpdate->NotifyListeners();

    physicWorld->Step(Time::elapseTime);
}

void mia::Render()
{
    mia::portraitRenderer->RenderPotraits();
}