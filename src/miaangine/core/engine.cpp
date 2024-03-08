#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = SDLHandle::Instance();
mia::EventManager *mia::events = EventManager::Instance();
mia::PortraitRenderer *mia::portraitRenderer = PortraitRenderer::Instance();
mia::PhysicWorld *mia::physicWorld = PhysicWorld::Instance();

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
    mia::portraitRenderer->RenderPotraits(sdlHandle->renderer);
}