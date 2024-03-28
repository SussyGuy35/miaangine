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
    
        bool _dynamic;

    public:
        // Attributes accessing
        bool isActive() const;
        const Object& master() const;
        const Vector2<>& size() const;
        const Vector2<>& offset() const;
        bool isColliding() const;
        bool isDynamic() const;

        bool SetActive(bool newState);
        Object& master();
        Vector2<>& size();
        Vector2<>& offset();
        bool SetColliding(bool newState);
        bool SetDynamic(bool newState);

        // Properties
        float minX() const;
        float maxX() const;
        float minY() const;
        float maxY() const;

        // Methods
    };
}

#endif