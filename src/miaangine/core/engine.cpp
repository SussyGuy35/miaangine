#include "engine.hpp"

std::unique_ptr<mia::SDLHandle>    mia::sdlHandle (mia::SDLHandle::Instance());
std::unique_ptr<mia::TimeManager>  mia::time      (mia::TimeManager::Instance());
std::unique_ptr<mia::InputManager> mia::input     (mia::InputManager::Instance());
std::unique_ptr<mia::EventManager> mia::event     (mia::EventManager::Instance());
std::unique_ptr<mia::Renderer>     mia::renderer  (mia::Renderer::Instance());
std::unique_ptr<mia::PhysicsWorld> mia::physics   (mia::PhysicsWorld::Instance());
std::unique_ptr<mia::DebugManager> mia::debug     (mia::DebugManager::Instance());

int mia::windowWidth = 10;
int mia::windowHeight = 10;
bool mia::fullscreenMode = 0;

void mia::Init(uint32_t width, uint32_t height, bool fullscreen)
{
    windowWidth = width;
    windowHeight = height;
    fullscreenMode = fullscreen;

    sdlHandle->Init(windowWidth, windowHeight, mia::fullscreenMode);

    SDL_Log("**MIAANGINE**\n");

    input->SetupKeyBind();
}

void mia::End()
{
    sdlHandle->Clear();

    // delete(sdlHandle);
    // delete(time);
    // delete(input);
    // delete(event);
    // delete(renderer);
    // delete(physics);
    // delete(debug);
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
    mia::renderer->Render(sdlHandle->renderer);
}