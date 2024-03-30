#include "input.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Input::Input():
        _keysPressState{false},
        _keysDownState{false},
        _keysUpState{false},
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

        SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
                _isQuit = true;
			    break;

			case SDL_KEYDOWN:
			case SDL_KEYUP:
                UpdateKeyInputEvent();
			    break;

			default:
			    break;
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