#include "generic-task.hpp"

#include "engine-components.hpp"

namespace mia
{
    GenericTask::GenericTask():
        windowWidth(0),
        windowHeight(0),
        fullscreenMode(0)
    {}

    GenericTask::~GenericTask()
    {}

    void GenericTask::Init(uint32_t width, uint32_t height, bool fullscreen)
    {
        windowWidth = width;
        windowHeight = height;
        fullscreenMode = fullscreen;

        sdl.Init(windowWidth, windowHeight, fullscreenMode);

        debug.Message("\n=== INIT SUCCESSFUL ===\n\n");

        input.SetupKeyBind();
    }

    void GenericTask::End()
    {
        sdl.Clear();
    }

    void GenericTask::NewFrame()
    {
        event.onEnterNewFrame().NotifyListeners();

        time.Step();
        input.Update();

        event.primaryUpdate().NotifyListeners();

        physics.Step(time.deltaTime());
    }

    void GenericTask::Render()
    {
        renderer.Render(sdl.renderer);
    }
}