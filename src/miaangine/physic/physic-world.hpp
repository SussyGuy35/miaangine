#ifndef _MIA_PHYSIC_WORLD_HPP
#define _MIA_PHYSIC_WORLD_HPP

#include <vector>

#include "body.hpp"

namespace mia
{
    class PhysicWorld
    {
    public:
        PhysicWorld();

    private:
        std::vector<Body> _bodies;

        
    };
}

#endif