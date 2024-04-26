#include "input.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Input::Input():
        _keysPressState{false},
        _keysDownState{false},
        _keysUpState{false},
        _mousePos(v2f::zero()),
        _mouseDown(false),
        _isQuit(false)
    {}

    Input::~Input()
    {}
#pragma endregion    

#pragma region Public method
    void Input::Update()
    {
        memset(_keysDownState, 0, SDL_NUM_SCANCODES);
		memset(_keysUpState, 0, SDL_NUM_SCANCODES);
        _mouseDown = false;

        SDL_Event event;
		while (SDL_PollEvent(&event))
		{
            if (event.type == SDL_QUIT)
            {
                _isQuit = true;
            }

            if (event.type == SDL_MOUSEMOTION)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                _mousePos = v2f(x, y);
            }

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                _mouseDown = true;
            }

            if (event.type == SDL_KEYUP || event.type == SDL_KEYDOWN)
            {
                UpdateKeyInputEvent();
            }
		}
    }

    bool Input::getKey(int key) const
    {
        return _keysPressState[key];
    }
    bool Input::getKeyDown(int key) const
    {
        return _keysDownState[key];
    }
    bool Input::getKeyUp(int key) const
    {
        return _keysUpState[key];
    }
    v2f Input::getMousePosition() const
    {
        return _mousePos;
    }
    bool Input::getMouseButtonDown() const
    {
        return _mouseDown;
    }
    bool Input::isQuit() const 
    {
        return _isQuit;
    }
#pragma endregion

#pragma region Private method
    void Input::UpdateKeyInputEvent()
	{
		const uint8_t* _currentKeyState = SDL_GetKeyboardState(NULL);

		for (int i = 0; i < SDL_NUM_SCANCODES; i++)
		{
            if (!_keysPressState[i] && _currentKeyState[i])
            {
                _keysDownState[i] = 1;
            }
            if (_keysPressState[i] && !_currentKeyState[i])
            {
                _keysUpState[i] = 1;
            }

			_keysPressState[i] = _currentKeyState[i];
		}
	}
#pragma endregion
}