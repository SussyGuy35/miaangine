#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = new mia::SDLHandle();
mia::EventManager *mia::events = new mia::EventManager();
mia::InputManager *mia::inputs = new mia::InputManager();
mia::PortraitRenderer *mia::portraitRenderer = new mia::PortraitRenderer();
mia::PhysicWorld *mia::physicWorld = new mia::PhysicWorld();

void mia::Init(uint32_t width, uint32_t height, bool fullscreen)
{
    SDL_Log("**MIAANGINE**\n");

    sdlHandle->Init(width, height, fullscreen);
    sdlHandle->Log();

    inputs->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(events);
    delete(inputs);
    delete(portraitRenderer);
    delete(physicWorld);
}

void mia::NewFrame()
{
    events->onEnterNewFrame->NotifyListeners();

    Time::Step();
    inputs->Update();

    events->primaryUpdate->NotifyListeners();

    physicWorld->Step(Time::elapseTime);
}

void mia::Render()
{
    mia::portraitRenderer->RenderPotraits();
}