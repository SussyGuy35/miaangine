#ifndef _MIA_RECT_HPP
#define _MIA_RECT_HPP

#include "vector.hpp"

namespace mia
{
    class rect
    {
    public:
        v2f pos;
        v2f siz;

        rect(v2f pos = v2f::zero(), v2f siz = v2f::one()):
            pos(pos),
            siz(siz)
        {}

        inline bool contain(const v2f& point) const
        {
            return (
                pos.x         < point.x && 
                pos.x + siz.x > point.x &&
                pos.y         < point.y && 
                pos.y + siz.y > point.y
            );
        }

        inline bool contain(const rect& other) const
        {
            return (
                pos.x         < other.pos.x               && 
                pos.x + siz.x > other.pos.x + other.siz.x &&
                pos.y         < other.pos.y               && 
                pos.y + siz.y > other.pos.y + other.siz.y
            );
        }

        inline bool overlap(const rect& other) const
        {
            return (
                pos.x         < other.pos.x + other.siz.x && 
                pos.x + siz.x > other.pos.x               &&
                pos.y         < other.pos.y + other.siz.y && 
                pos.y + siz.y > other.pos.y
            );
        }
    };
}

#endif