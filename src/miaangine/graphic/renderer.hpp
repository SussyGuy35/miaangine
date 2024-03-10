#ifndef _MIA_RENDERER_HPP
#define _MID_RENDERER_HPP

namespace mia
{
    class Renderer
    {
    private:
        static Renderer *__instance;
    public:
        static Renderer* Instance() 
        {
            if (!__instance) __instance = new Renderer(); 
            return __instance;
        }

        Renderer(const Renderer&) = delete;
        void operator=(const Renderer&) = delete;
    
    private:
        Renderer();

    public:
        ~Renderer();
    };
}

#endif