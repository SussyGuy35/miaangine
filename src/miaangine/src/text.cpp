#include "text.hpp"

#include "camera.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Text::Text(UI *master, const char *content, v2f offset):
        _master(master),
        _content(content),
        _offset(offset)
    {
        _master->SetText(this);
    }

    Text::~Text()
    {}
#pragma endregion

#pragma region GetSet method
    const UI& Text::master() const
    {
        if (!_master)
        {
            // FIXME
        }

        return *_master;
    }
    const char* Text::content() const
    {
        return _content.str();
    }
    const v2f& Text::offset() const
    {
        return _offset;
    }

    UI& Text::master()
    {
        if (!_master)
        {
            // FIXME
        }

        return *_master;
    }
    string& Text::content()
    {
        return _content;
    }
    v2f& Text::offset()
    {
        return _offset;
    }
#pragma endregion

#pragma region Public method
    UI& Text::ChangeMaster(UI *newMaster)
    {
        if (!newMaster)
        {
            // FIXME
        }

        _master = newMaster;
        return *_master;
    }

    v2f Text::GetPos() const
    {
        v2f res;
        res.x = Camera::Instance().getScreenWidth()  * master().center().x + _offset.x;
        res.y = Camera::Instance().getScreenHeight() * master().center().y + _offset.y;
        return res;
    }
#pragma endregion

#pragma region Inherited method
    int Text::getID() const 
    {
        return _ENTITY_IMAGE;
    }
    const char* Text::ToStr() const
    {
        return "Text";
    }
#pragma endregion
}