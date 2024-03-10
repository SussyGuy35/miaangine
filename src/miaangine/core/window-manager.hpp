#ifndef _MIA_WINDOW_MANAGER_HPP
#define _MIA_WINDOW_MANAGER_HPP

namespace mia
{
    class WindowManager
    {
    private:
        static WindowManager *__instance;
    public:
        static WindowManager* Instance() 
        {
            if (!__instance) __instance = new WindowManager(); 
            return __instance;
        }

        WindowManager(const WindowManager&) = delete;
        void operator=(const WindowManager&) = delete;

    private:
        WindowManager();
    
    public:
        ~WindowManager();

    private:
        int _width, _height;
        bool _fullscreen;

    public:
        const int &width = _width;
        const int &height = _height;
        const bool &fullscreen = _fullscreen;

        void ChangeWindow(int width, int height);
        void ChangeFullscreen(bool state);
    };
} 

#endif