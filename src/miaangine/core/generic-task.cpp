#include "generic-task.hpp"

#ifndef _MIA_ENGINE_COMPONENTS_HPP
#include "engine-components.hpp"
#endif

namespace mia
{
    #pragma region Constructor_Destructor
    GenericTask::GenericTask():
        windowWidth(0),
        windowHeight(0),
        fullscreenMode(0)
    {}

    GenericTask::~GenericTask()
    {}
    #pragma endregion

    #pragma region Public methods
    int GenericTask::Init()
    {
        debug().Message("\n=== INITIALIZING...\n");

        windowWidth = WINDOW_WIDTH;
        windowHeight = WINDOW_HEIGHT;
        fullscreenMode = FULLSCREEN_MODE;

        if (CreateWindow(windowWidth, windowHeight, fullscreenMode) != 0) return -1;

        if (!input().SetupKeyBind()) 
        {
            debug().Error("Setup keybind failed!");
            return -1;
        }
        else 
        {
            debug().Message("=== Setup keybinds successful\n");
        }

        debug().Message("=== INITIALIZE SUCCESSFUL\n\n");

        return 0;
    }

    void GenericTask::End()
    {
        ClearWindow();
    }

    void GenericTask::NewFrame()
    {
        event().onEnterNewFrame().NotifyListeners();

        time().Step();
        input().Update();

        event().primaryUpdate().NotifyListeners();

        // physics().Step(time.deltaTime()); //TODO
    }

    void GenericTask::Render()
    {
        render().Render(renderer);
    }
    #pragma endregion

    #pragma region SDL-related methods
    int GenericTask::CreateWindow(int width, int height, bool fullscreen)
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) 
        {
            debug().Error("SDL could not initialize! : %s", SDL_GetError());
            return -1;
        }

        window = SDL_CreateWindow( 
            "", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            width,
            height,
            SDL_WINDOW_OPENGL
        );
        if (window == nullptr)
        {
            debug().Error("Window could not be created! : %s", SDL_GetError());
            return -1;
        }

        renderer = SDL_CreateRenderer(
            window, 
            -1, 
            SDL_RENDERER_ACCELERATED
        );
        if (renderer == nullptr) 
        {
            debug().Error("Renderer could not be created! : %s", SDL_GetError());
            return -1;
        }

        int imgFlags = IMG_INIT_PNG;
        if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) 
        {
            debug().Error("IMG_PNG could not be created! : %s", SDL_GetError());
            return -1;
        }

        debug().Message("=== SDL initialize successful\n");
        return 0;
    }

    void GenericTask::ClearWindow()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        IMG_Quit();
    }
    #pragma endregion
}