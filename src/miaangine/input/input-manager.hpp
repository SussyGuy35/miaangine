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

        static bool GetButton(std::string _button);
        static bool GetButtonDown(std::string _button);
        static bool GetButtonUp(std::string _button);
        static bool GetKey(int _key);
        static bool GetKeyDown(int _key);
        static bool GetKeyUp(int _key);
    };
}

#endif