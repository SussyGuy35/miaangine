#include "input-manager.hpp"
#include "keybind.hpp"

#include <iostream>

namespace mia 
{
    KeyBind::KeyBind():
        m_keyBind(
        {
            // ================================================
            // ================== KEYBINDING ==================
            {
                "Up", {SDL_SCANCODE_W, SDL_SCANCODE_SPACE}
            },
            {
                "Down", {SDL_SCANCODE_S, SDL_SCANCODE_SPACE}
            },
            {
                "Left", {SDL_SCANCODE_A, SDL_SCANCODE_SPACE}
            },
            {
                "Right", {SDL_SCANCODE_D, SDL_SCANCODE_SPACE}
            },
            {
                "Jump", {SDL_SCANCODE_SPACE, 0}
            },
            // ================================================
        })
    {}

    std::unique_ptr<KeyBind> Input::m_keyBind = std::make_unique<KeyBind>();

    bool Input::s_keyState[SDL_NUM_SCANCODES] = {false};
    bool Input::s_keyDownState[SDL_NUM_SCANCODES] = {false};
    bool Input::s_keyUpState[SDL_NUM_SCANCODES] = {false};

    bool Input::s_isQuit = false;

    void Input::SetupKeyBind()
    {
        m_keyBind->PopulateKeyMap();
    }

    void Input::RegisterInput()
    {
        memset(s_keyDownState, 0, SDL_NUM_SCANCODES);
		memset(s_keyUpState, 0, SDL_NUM_SCANCODES);

        SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
                s_isQuit = true;
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

    bool Input::GetButton(std::string _button)
	{
		return 
            s_keyState[m_keyBind->GetMainKeyBind(_button)] || 
            s_keyState[m_keyBind->GetAltKeyBind(_button)];
	}
	bool Input::GetButtonDown(std::string _button)
	{
		return 
            s_keyDownState[m_keyBind->GetMainKeyBind(_button)] || 
            s_keyDownState[m_keyBind->GetAltKeyBind(_button)];
	}
	bool Input::GetButtonUp(std::string _button)
	{
		return  
            s_keyUpState[m_keyBind->GetMainKeyBind(_button)] || 
            s_keyUpState[m_keyBind->GetAltKeyBind(_button)];
	}

    bool Input::GetKey(int _key)
    {
        return s_keyState[_key];
    }
    bool Input::GetKeyDown(int _key)
    {
        return s_keyDownState[_key];
    }
    bool Input::GetKeyUp(int _key)
    {
        return s_keyUpState[_key];
    }

    uint16_t KeyBind::GetMainKeyBind(std::string _name)
    {

        return m_buttonMap[_name] & (SDL_NUM_SCANCODES - 1);
    }

    uint16_t KeyBind::GetAltKeyBind(std::string _name)
    {
        return m_buttonMap[_name] >> 9;
    }

	void Input::UpdateKeyInputEvent()
	{
		const uint8_t* _currentKeyState = SDL_GetKeyboardState(NULL);

		for (int i = 0; i < SDL_NUM_SCANCODES; i++)
		{
            if (!s_keyState[i] && _currentKeyState[i])
            {
                s_keyDownState[i] = 1;
            }
            if (s_keyState[i] && !_currentKeyState[i])
            {
                s_keyUpState[i] = 1;
            }

			s_keyState[i] = _currentKeyState[i];
		}
	}

    void KeyBind::PopulateKeyMap()
    {
        for (auto _button : m_keyBind)
        {
            m_buttonMap.insert(std::make_pair
            (
                _button.first,
                _button.second.first + _button.second.second * SDL_NUM_SCANCODES
            ));
        }
    }
}