#ifndef _MIA_COLLIDER_HPP
#define _MIA_COLLIDER_HPP

#include "util/math.hpp"

#include "body.hpp"
#include "object/world-object.hpp"

namespace mia
{
    class Collider
    {
    public:
        Collider(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        Collider(float sx, float sy, float ox = 0, float oy = 0);

        virtual ~Collider();

    private:
        string _ucName;
        Vector2 _ucPosition;

        Vector2 _size;
        Vector2 _offset;
        Body* _body;
        WorldObject *_master;

    public:
        string& name();
        Vector2& position();
        Vector2& size();
        Vector2& offset();
        Body* body();
        WorldObject* master();

        const string& name() const;
        const Vector2& position() const;
        const Vector2& size() const;
        const Vector2& offset() const;
        const Body* body() const;
        const WorldObject* master() const;
        
        const Vector2 cornerMin() const;
        const Vector2 cornerMax() const;

        bool CheckColliding(Collider *other);

        void ShiftBody(Body *body);
        void ShiftMaster(WorldObject *master);
    };
}

#endif