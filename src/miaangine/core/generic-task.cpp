#include "generic-task.hpp"

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
    void GenericTask::Init(uint32_t width, uint32_t height, bool fullscreen)
    {
        windowWidth = width;
        windowHeight = height;
        fullscreenMode = fullscreen;

        CreateWindow(windowWidth, windowHeight, fullscreenMode);

        // debug.Message("\n=== INIT SUCCESSFUL ===\n\n"); // TODO

        // input.SetupKeyBind(); 
    }

    void GenericTask::End()
    {
        ClearWindow();
    }

    void GenericTask::NewFrame() // TODO
    {
        // event.onEnterNewFrame().NotifyListeners();

        // time.Step();
        // input.Update();

        // event.primaryUpdate().NotifyListeners();

        // physics.Step(time.deltaTime());
    }

    void GenericTask::Render() //TODO
    {
        // renderer.Render(sdl.renderer);
    }
    #pragma endregion

    #pragma region SDL-related methods
    int GenericTask::CreateWindow(int width, int height, bool fullscreen)
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0) return false;

        window = SDL_CreateWindow( 
            "MIAANGINE", 
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            width,
            height,
            SDL_WINDOW_OPENGL
        );
        if (window == nullptr)
        {
            //TODO Debug
            return -1;
        }

        renderer = SDL_CreateRenderer(
            window, 
            -1, 
            SDL_RENDERER_ACCELERATED
        );
        if (renderer == nullptr) 
        {
            //TODO Debug
            return -1;
        }

        int imgFlags = IMG_INIT_PNG;
        if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) 
        {
            //TODO Debug
            return -1;
        }

        //TODO Debug
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