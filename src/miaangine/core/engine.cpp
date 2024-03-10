#include "engine.hpp"

mia::SDLHandle *mia::sdlHandle = SDLHandle::Instance();
mia::WindowUtilities *mia::windowManager = WindowUtilities::Instance();
mia::TimeManager *mia::time = TimeManager::Instance();
mia::InputManager *mia::input = InputManager::Instance();
mia::EventManager *mia::event = EventManager::Instance();
mia::PortraitRenderer *mia::portraitRenderer = PortraitRenderer::Instance();
mia::PhysicsWorld *mia::physics = PhysicsWorld::Instance();
mia::DebugManager *mia::debug = DebugManager::Instance();

int mia::windowWidth = 10;
int mia::windowHeight = 10;
bool mia::fullscreen = 0;

void mia::Init(uint32_t width, uint32_t height, bool fullscreen)
{
    windowWidth = width;
    windowHeight = height;
    mia::fullscreen = fullscreen;

    sdlHandle->Init(windowWidth, windowHeight, mia::fullscreen);

    SDL_Log("**MIAANGINE**\n");

    input->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    delete(sdlHandle);
    delete(windowManager);
    delete(time);
    delete(input);
    delete(event);
    delete(portraitRenderer);
    delete(physics);
    delete(debug);
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