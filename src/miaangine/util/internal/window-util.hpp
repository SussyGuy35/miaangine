#ifndef _MIA_WINDOW_UTIL_HPP
#define _MIA_WINDOW_UTIL_HPP

namespace mia
{
    class WindowUtilities
    {
    private:
        static WindowUtilities *__instance;
    public:
        static WindowUtilities* Instance() 
        {
            if (!__instance) __instance = new WindowUtilities(); 
            return __instance;
        }

        WindowUtilities(const WindowUtilities&) = delete;
        void operator=(const WindowUtilities&) = delete;

    private:
        WindowUtilities();
    
    public:
        ~WindowUtilities();

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