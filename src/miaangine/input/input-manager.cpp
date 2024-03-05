#include "input-manager.hpp"
#include "keybind.hpp"

#include <iostream>
#include <string.h>

namespace mia 
{
    KeyBind::KeyBind(): //TODO
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

    std::unique_ptr<KeyBind> InputManager::_keyBind = std::make_unique<KeyBind>();

    bool InputManager::_keyState[SDL_NUM_SCANCODES] = {false};
    bool InputManager::_keyDownState[SDL_NUM_SCANCODES] = {false};
    bool InputManager::_keyUpState[SDL_NUM_SCANCODES] = {false};

    bool InputManager::_isQuit = false;

    void InputManager::SetupKeyBind()
    {
        _keyBind->PopulateKeyMap();
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

    bool InputManager::GetButton(const char *button)
	{
		return 
            _keyState[_keyBind->GetMainKeyBind(button)] || 
            _keyState[_keyBind->GetAltKeyBind(button)];
	}
	bool InputManager::GetButtonDown(const char *button)
	{
		return 
            _keyDownState[_keyBind->GetMainKeyBind(button)] || 
            _keyDownState[_keyBind->GetAltKeyBind(button)];
	}
	bool InputManager::GetButtonUp(const char *button)
	{
		return  
            _keyUpState[_keyBind->GetMainKeyBind(button)] || 
            _keyUpState[_keyBind->GetAltKeyBind(button)];
	}

    bool InputManager::GetKey(int key)
    {
        return _keyState[key];
    }
    bool InputManager::GetKeyDown(int key)
    {
        return _keyDownState[key];
    }
    bool InputManager::GetKeyUp(int key)
    {
        return _keyUpState[key];
    }

    uint16_t KeyBind::GetMainKeyBind(const char *keyName)
    {
        return _buttonMap[keyName] & (SDL_NUM_SCANCODES - 1);
    }

    uint16_t KeyBind::GetAltKeyBind(const char *keyName)
    {
        return _buttonMap[keyName] >> 9;
    }

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

    void KeyBind::PopulateKeyMap()
    {
        for (auto _button : _keyBind)
        {
            _buttonMap.insert(std::make_pair
            (
                _button.first,
                _button.second.first + _button.second.second * SDL_NUM_SCANCODES
            ));
        }
    }
}