#include "input-manager.hpp"

#include <iostream>
#include <string.h>

namespace mia 
{
    #pragma region Setup keys bind
    KeyBind::KeyBind(): //FIXME
        _keyBind(
        {
            // ================================================
            // ================== KEYBINDING ==================
            {
                "Up", 
                {SDL_SCANCODE_W, SDL_SCANCODE_SPACE}
            },
            {
                "Down", 
                {SDL_SCANCODE_S, SDL_SCANCODE_SPACE}
            },
            {
                "Left", 
                {SDL_SCANCODE_A, SDL_SCANCODE_SPACE}
            },
            {
                "Right", 
                {SDL_SCANCODE_D, SDL_SCANCODE_SPACE}
            },
            {
                "Jump", 
                {SDL_SCANCODE_SPACE, 0}
            },
            // ================================================
        })
    {}
    #pragma endregion

    #pragma region Constructor_Destructor
    InputManager::InputManager():
        _keyBind(std::make_unique<KeyBind>()),
        _keyState{false},
        _keyDownState{false},
        _keyUpState{false},
        _isQuit(false)
    {}

    InputManager::~InputManager()
    {}
    #pragma endregion

    #pragma region Setup methods
    bool InputManager::SetupKeyBind()
    {
        return _keyBind->PopulateKeyMap();
    }

    void InputManager::Update()
    {
        memset(_keyDownState, 0, SDL_NUM_SCANCODES);
		memset(_keyUpState, 0, SDL_NUM_SCANCODES);

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
    #pragma endregion

    #pragma region Get methods
    bool InputManager::isQuit() const
    {
        return _isQuit;
    }

    bool InputManager::GetButton(const char *button) const
	{
		return 
            _keyState[_keyBind->GetMainKeyBind(button)] || 
            _keyState[_keyBind->GetAltKeyBind(button)];
	}
	bool InputManager::GetButtonDown(const char *button) const
	{
		return 
            _keyDownState[_keyBind->GetMainKeyBind(button)] || 
            _keyDownState[_keyBind->GetAltKeyBind(button)];
	}
	bool InputManager::GetButtonUp(const char *button) const
	{
		return  
            _keyUpState[_keyBind->GetMainKeyBind(button)] || 
            _keyUpState[_keyBind->GetAltKeyBind(button)];
	}

    bool InputManager::GetKey(int key) const
    {
        return _keyState[key];
    }
    bool InputManager::GetKeyDown(int key) const
    {
        return _keyDownState[key];
    }
    bool InputManager::GetKeyUp(int key) const
    {
        return _keyUpState[key];
    }
    #pragma endregion

    #pragma region Internal methods
	void InputManager::UpdateKeyInputEvent()
	{
		const uint8_t* _currentKeyState = SDL_GetKeyboardState(NULL);

		for (int i = 0; i < SDL_NUM_SCANCODES; i++)
		{
            if (!_keyState[i] && _currentKeyState[i])
            {
                _keyDownState[i] = 1;
            }
            if (_keyState[i] && !_currentKeyState[i])
            {
                _keyUpState[i] = 1;
            }

			_keyState[i] = _currentKeyState[i];
		}
	}
    #pragma endregion
}