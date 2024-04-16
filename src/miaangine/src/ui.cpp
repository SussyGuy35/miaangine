#include "ui.hpp"

namespace mia
{
#pragma region Contructor Destructor
    // UI::UI(const char *name, v2f position):
    //     _name(name),
    //     _tag(0),
    //     _position(position),
    //     _portrait(nullptr),
    //     _body(nullptr)
    // {}
    // UI::UI(const char *name, float x, float y):
    //     _name(name),
    //     _tag(0),
    //     _position(v2f(x, y)),
    //     _portrait(nullptr),
    //     _body(nullptr)
    // {}
    // UI::UI(float x, float y):
    //     _name("Untitled"),
    //     _tag(0),
    //     _position(v2f(x, y)),
    //     _portrait(nullptr),
    //     _body(nullptr)
    // {}

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