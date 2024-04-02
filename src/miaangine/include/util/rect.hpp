#ifndef _MIA_RECT_HPP
#define _MIA_RECT_HPP

#include "vector.hpp"

namespace mia
{
    class rect
    {
    public:
        v2f position;
        v2f size;

        rect(v2f pos = v2f::zero(), v2f siz = v2f::one()):
            position(pos),
            size(siz)
        {}

        inline bool contain(const v2f& point) const
        {
            return (
                point.x > position.x          &&
                point.x < position.x + size.x &&
                point.y > position.y          &&
                point.y < position.y + size.y
            );
        }

        inline bool contain(const rect& other) const
        {
            return (
                position.x          < other.position.x                && 
                position.x + size.x < other.position.x + other.size.x &&
                position.y          < other.position.y                && 
                position.y + size.y < other.position.y + other.size.y
            );
        }

        inline bool contain(const rect& other) const
        {
            return (
                position.x          < other.position.x + other.size.x && 
                position.x + size.x > other.position.x                &&
                position.y          < other.position.y + other.size.y && 
                position.y + size.y > other.position.y
            );
        }
    };
}

#endif