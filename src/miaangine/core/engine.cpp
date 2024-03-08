#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = SDLHandle::Instance();
mia::TimeManager *mia::time = TimeManager::Instance();
mia::InputManager *mia::input = InputManager::Instance();
mia::EventManager *mia::event = EventManager::Instance();
mia::PortraitRenderer *mia::portraitRenderer = PortraitRenderer::Instance();
mia::PhysicsWorld *mia::physics = PhysicsWorld::Instance();

void mia::Init(uint32_t width, uint32_t height, bool fullscreen)
{
    SDL_Log("**MIAANGINE**\n");

    sdlHandle->Init(width, height, fullscreen);

    input->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(time);
    delete(input);
    delete(event);
    delete(portraitRenderer);
    delete(physics);
}

void mia::NewFrame()
{
    event->onEnterNewFrame->NotifyListeners();

    time->Step();
    input->Update();

    event->primaryUpdate->NotifyListeners();

    physics->Step(time->elapseTime);
}

void mia::Render()
{
    mia::portraitRenderer->RenderPotraits(sdlHandle->renderer);
}