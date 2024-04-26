#include "ui.hpp"

#include "image.hpp"

namespace mia
{
#pragma region Contructor Destructor
    UI::UI(const char *name, v2f center, v2f offset):
        _name(name),
        _tag(0),
        _center(center),
        _offset(offset),
        _image(nullptr)
    {}
    UI::UI(const char *name, float cx, float cy, float ox, float oy):
        _name(name),
        _tag(0),
        _center(v2f(cx, cy)),
        _offset(v2f(ox, oy)),
        _image(nullptr)
    {}
    UI::UI(v2f center, v2f offset):
        _name("Untitled"),
        _tag(0),
        _center(center),
        _offset(offset),
        _image(nullptr)
    {}
    UI::UI(float cx, float cy, float ox, float oy):
        _name("Untitled"),
        _tag(0),
        _center(v2f(cx, cy)),
        _offset(v2f(ox, oy)),
        _image(nullptr)
    {}

    UI::~UI()
    {
        // TODO Add destroy method

        delete _image;
    }
#pragma endregion

#pragma region GetSet-method
    string UI::name() const
    {
        return _name;
    }
    uint32_t UI::getTag() const
    {
        return _tag;
    }
    const v2f& UI::center() const
    {
        return _center;
    }
    const v2f& UI::offset() const
    {
        return _offset;
    }
    const Image& UI::image() const
    {
        if (!_image) 
        {
            // FIXME
        }

        return *_image;
    }
    const Text& UI::text() const
    {
        if (!_text) 
        {
            // FIXME
        }

        return *_text;
    }

    string& UI::name()
    {
        return _name;
    }
    v2f& UI::center()
    {
        return _center;
    }
    v2f& UI::offset()
    {
        return _offset;
    }
    Image& UI::image()
    {
        if (!_image) 
        {
            // FIXME
        }

        return *_image;
    }
    Text& UI::text() 
    {
        if (!_text) 
        {
            // FIXME
        }

        return *_text;
    }
#pragma endregion

#pragma region Public method
    bool UI::IsContainTag(int tag)
    {
        // TODO safety
        return ((_tag >> tag) & 1);
    }
    uint32_t UI::AddTag(int tag)
    {
        // TODO safety
        _tag |= (1 << tag);
    }
    uint32_t UI::RemoveTag(int tag)
    {
        // TODO safety
        _tag &= ~(1 << tag);
    }

    Image& UI::SetImage(Image *image)
    {
        _image = image;
    }

    Text& UI::SetText(Text *text)
    {
        _text = text;
    }

#pragma endregion

#pragma region Inherited method
    int UI::getID() const 
    {
        return _ENTITY_UI;
    }
    const char* UI::ToStr() const
    {
        return "UI";
    }
#pragma endregion
}