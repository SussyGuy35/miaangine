#ifndef _MIA_INPUT_MANAGER_HPP
#define _MIA_INPUT_MANAGER_HPP

#include <SDL.h>
#include <memory>

#include "keybind.hpp"

namespace mia 
{
    class InputManager //FIXME
    {
    private:
        static InputManager *__instance;
    public:
        static InputManager* Instance() 
        {
            if (!__instance) __instance = new InputManager(); 
            return __instance;
        }

        InputManager(const InputManager&) = delete;
        void operator=(const InputManager&) = delete;

    private:
        InputManager();

    public:
        ~InputManager();

    private:
        std::unique_ptr<KeyBind> _keyBind;

        bool _keyState[SDL_NUM_SCANCODES];
        bool _keyDownState[SDL_NUM_SCANCODES];
        bool _keyUpState[SDL_NUM_SCANCODES];

        bool _isQuit;

        void UpdateKeyInputEvent();
    
    public:
        void SetupKeyBind();
        void Update();

        bool IsQuit() { return _isQuit; } //FIXME

        bool GetButton(const char *button);
        bool GetButtonDown(const char *button);
        bool GetButtonUp(const char *button);
        bool GetKey(int key);
        bool GetKeyDown(int key);
        bool GetKeyUp(int key);
    };
}

#endif