#ifndef _MIA_INPUT_MANAGER_HPP
#define _MIA_INPUT_MANAGER_HPP

#include <SDL.h>
#include <memory>

#include "keybind.hpp"

namespace mia 
{
    class InputManager
    {
    public:
        InputManager() {} 

    private:
        static std::unique_ptr<KeyBind> _keyBind;

        static bool _keyState[SDL_NUM_SCANCODES];
        static bool _keyDownState[SDL_NUM_SCANCODES];
        static bool _keyUpState[SDL_NUM_SCANCODES];

        static bool _isQuit;

        static void UpdateKeyInputEvent();
    
    public:
        static void SetupKeyBind();
        static void RegisterInput();

        static bool IsQuit() { return _isQuit; }

        static bool GetButton(const char *button);
        static bool GetButtonDown(const char *button);
        static bool GetButtonUp(const char *button);
        static bool GetKey(int key);
        static bool GetKeyDown(int key);
        static bool GetKeyUp(int key);
    };
}

#endif