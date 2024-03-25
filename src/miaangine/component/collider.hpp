#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include "object/object.hpp"

#include "util/math.hpp"

namespace mia
{
    class Collider
    {
    private:
        friend class Object;
        
        Collider(Object *master, Vector2<> size, Vector2<> offset);

        virtual ~Collider();

    private:
        // Attributes
        bool _isActive;
        Object *_master;

        Vector2<> _size;
        Vector2<> _offset;

        bool _isColliding;
    
    public:
        // Attributes accessing
        bool isActive() const;
        const Object& master() const;
        const Vector2<>& size() const;
        const Vector2<>& offset() const;

        bool SetActive(bool newState);
        Object& master();
        Vector2<>& size();
        Vector2<>& offset();

        // Properties
        Vector2<> minX() const;
        Vector2<> maxX() const;
        Vector2<> minY() const;
        Vector2<> minY() const;
        bool isColliding() const;

        // Methods
    };
}

#endif