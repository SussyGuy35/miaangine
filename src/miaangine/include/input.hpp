#ifndef _MIA_INPUT_HPP
#define _MIA_INPUT_HPP

#include "common.hpp"

namespace mia
{
    class Input : public Singleton<Input>
    {
    #pragma region Constructor Destructor
    private:
        friend class Singleton<Input>;
        Input();
        ~Input();
    #pragma endregion

    #pragma region Attribute
    private:
        bool _keysPressState[SDL_NUM_SCANCODES];
        bool _keysDownState[SDL_NUM_SCANCODES];
        bool _keysUpState[SDL_NUM_SCANCODES];

        bool _isQuit;
    #pragma endregion

    #pragma region Public method
    public:
        void Update();

        bool getKey(int key) const;
        bool getKeyDown(int key) const;
        bool getKeyUp(int key) const;
    #pragma endregion

    #pragma region Private method
    private:
        void UpdateKeyInputEvent();
    #pragma endregion
    };
}

#endif