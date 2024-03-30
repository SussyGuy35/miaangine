#ifndef _MIA_INPUT_HPP
#define _MIA_INPUT_HPP

#include "common.hpp"

namespace mia
{
    class Input : public Singleton<Input>
    {
    private:
        friend class Singleton<Input>;
        Input();
        ~Input();

    private:
        bool _keysPressState[SDL_NUM_SCANCODES];
        bool _keysDownState[SDL_NUM_SCANCODES];
        bool _keysUpState[SDL_NUM_SCANCODES];

        bool _isQuit;

    public:
        void Update();

        bool getKey(int key) const;
        bool getKeyDown(int key) const;
        bool getKeyUp(int key) const;

        bool isQuit() const;

    private:
        void UpdateKeyInputEvent();
    };
}

#endif