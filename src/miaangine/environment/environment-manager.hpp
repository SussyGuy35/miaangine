#ifndef _MIA_OBJECT_MAKER_HPP
#define _MIA_OBJECT_MAKER_HPP

#include <memory>

#include "object.hpp"

#include "object-container.hpp"

namespace mia
{
    class Environment
    {
    private:
        Environment() = delete;
        // ~Environment();

    public:
        static std::shared_ptr<ObjectContainer> container;

    public:
        static Object* Create(Vector2 _position = Vector2::zero());
        static Object* Create(float _x, float _y);
    };
}

#endif