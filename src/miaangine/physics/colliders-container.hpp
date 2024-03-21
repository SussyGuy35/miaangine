#ifndef _MIA_COLLIDERS_CONTAINER_HPP
#define _MIA_COLLIDERS_CONTAINER_HPP

#include "vendor/Quadtree/Quadtree.h"

#include "util/singleton.hpp"

namespace mia
{
    class CollidersContainer : public Singleton<CollidersContainer>
    {
    private:
        friend class Singleton<CollidersContainer>;
        CollidersContainer();
        ~CollidersContainer();

    private:
        struct Node
        {
            Box<float> box;
            std::size_t id;
        };
        auto getBox = [](Node* node)
        {
            return node->box;
        };
        auto quadtree = Quadtree<Node*, decltype(getBox)>(box, getBox);

        
    };
}

#endif