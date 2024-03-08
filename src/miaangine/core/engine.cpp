#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = SDLHandle::Instance();
mia::InputManager *mia::input = InputManager::Instance();
mia::EventManager *mia::event = EventManager::Instance();
mia::PortraitRenderer *mia::portraitRenderer = PortraitRenderer::Instance();
mia::PhysicsWorld *mia::physics = PhysicsWorld::Instance();

void mia::Init(uint32_t width, uint32_t height, bool fullscreen)
{
    SDL_Log("**MIAANGINE**\n");

    sdlHandle->Init(width, height, fullscreen);
    sdlHandle->Log();

    input->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(event);
    delete(portraitRenderer);
    delete(physics);
}

void mia::NewFrame()
{
    event->onEnterNewFrame->NotifyListeners();

    Time::Step();
    input->Update();

    event->primaryUpdate->NotifyListeners();

    physics->Step(Time::elapseTime);
}

void mia::Render()
{
    mia::portraitRenderer->RenderPotraits(sdlHandle->renderer);
}