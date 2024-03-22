#ifndef _MIA_INPUT_MANAGER_HPP
#define _MIA_INPUT_MANAGER_HPP

#include <SDL.h>
#include <memory>

#include "util/singleton.hpp"

#include "keybind.hpp"

namespace mia 
{
    class InputManager : public Singleton<InputManager>
    {
    private:
        friend class Singleton<InputManager>;
        InputManager();
        ~InputManager();

    private:
        std::unique_ptr<KeyBind> _keyBind;

        bool _keyState[SDL_NUM_SCANCODES];
        bool _keyDownState[SDL_NUM_SCANCODES];
        bool _keyUpState[SDL_NUM_SCANCODES];

        bool _isQuit;
    
    public:
        // Setup methods
        void SetupKeyBind();
        void Update();

        // Get* methods
        inline bool isQuit() const;

        inline bool GetButton(const char *button) const;
        inline bool GetButtonDown(const char *button) const;
        inline bool GetButtonUp(const char *button) const;
        inline bool GetKey(int key) const;
        inline bool GetKeyDown(int key) const;
        inline bool GetKeyUp(int key) const;

    private:
        void UpdateKeyInputEvent();
    };
}

#endif