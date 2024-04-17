#ifndef _MIA_UI_HPP
#define _MIA_UI_HPP

#include "common.hpp"

#include "entity.hpp"

namespace mia 
{
    class Image;

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

    public:
        string name() const;
        uint32_t getTag() const;
        const v2f& center() const;
        const v2f& offset() const;
        const Image& image() const;

        string& name();
        v2f& center();
        v2f& offset();
        Image& image();

        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif