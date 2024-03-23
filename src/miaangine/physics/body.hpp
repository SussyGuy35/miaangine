// #ifndef _MIA_COLLIDER_HPP
// #define _MIA_COLLIDER_HPP

// #include "util/math.hpp"

// #include "object/world-object.hpp"

// namespace mia
// {
//     class Collider;
//     class Body
//     {
//     public:
//         Body(float mass = 1, vector2 initForce = vector2::zero());

//         virtual ~Body();

//     private:
//         string _ucName;
//         vector2 _ucPosition;

//         vector2 _velocity;
//         vector2 _force;
//         float _mass;
//         WorldObject *_master;

//     public:
//         string& name();
//         vector2& position();
//         vector2& velocity();
//         vector2& force();
//         float& mass();
//         WorldObject* master();

//         const string& name() const;
//         const vector2& position() const;
//         const vector2& velocity() const;
//         const vector2& force() const;
//         const float& mass() const;
//         const WorldObject* master() const;

//         vector2 AddForce(vector2 force);
//         vector2 AddAcceleration(vector2 acceleration);
        
//         void ShiftMaster(WorldObject *master);
//     };
// }

// #endif