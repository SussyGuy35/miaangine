#ifndef _MIA_INPUT_MANAGER_HPP
#define _MIA_INPUT_MANAGER_HPP

#include <SDL.h>
#include <memory>

#include "keybind.hpp"

namespace mia 
{
    class Input
    {
    private:
        Input() = delete;
        // ~Input();

    private:
        static std::unique_ptr<KeyBind> m_keyBind;

        static bool s_keyState[SDL_NUM_SCANCODES];
        static bool s_keyDownState[SDL_NUM_SCANCODES];
        static bool s_keyUpState[SDL_NUM_SCANCODES];

        static bool s_isQuit;

        static void UpdateKeyInputEvent();
    
    public:
        static void SetupKeyBind();
        static void RegisterInput();

        static bool IsQuit() { return s_isQuit; }

        static bool GetButton(std::string _button);
        static bool GetButtonDown(std::string _button);
        static bool GetButtonUp(std::string _button);
        static bool GetKey(int _key);
        static bool GetKeyDown(int _key);
        static bool GetKeyUp(int _key);
    };
}

#endif