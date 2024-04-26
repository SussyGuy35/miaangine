#ifndef _MIA_UI_HPP
#define _MIA_UI_HPP

#include "common.hpp"

#include "entity.hpp"

namespace mia 
{
    class Image;
    class Text;

    class UI : public Entity
    {
    public:
        UI(const char *name, v2f center = v2f::zero(), v2f offset = v2f::zero());
        UI(const char *name, float cx, float cy, float ox = 0, float oy = 0);
        UI(v2f center = v2f::zero(), v2f offset = v2f::zero());
        UI(float cx, float cy, float ox = 0, float oy = 0);
        virtual ~UI();

    private:
        string _name;
        uint32_t _tag;

        v2f _center;
        v2f _offset;

        Image *_image;
        Text *_text;

    public:
        string name() const;
        uint32_t getTag() const;
        const v2f& center() const;
        const v2f& offset() const;
        const Image& image() const;
        const Text& text() const;

        string& name();
        v2f& center();
        v2f& offset();
        Image& image();
        Text& text();

        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);

        Image& SetImage(Image *image);
        Text& SetText(Text *text);

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif