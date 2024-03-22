// #include "physics-world.hpp"

// #include "core/engine-components.hpp"

// #include <algorithm>

// namespace mia
// {
//     PhysicsWorld::PhysicsWorld():
//         _gravity(Vector2(0.0, 9.81))
//     {}

//     PhysicsWorld::~PhysicsWorld()
//     {}

//     void PhysicsWorld::RegisterBody(Body *body)
//     {
//         _bodies.push_back(body);
//     }

//     void PhysicsWorld::RemoveBody(Body *body)
//     {
//         auto listenerIterator = std::find(_bodies.begin(), _bodies.end(), body);

//         if (listenerIterator != _bodies.end())
//         {
//             _bodies.erase(listenerIterator);
//         }
//     }

//     void PhysicsWorld::Step(double elapsedTime)
//     {
//         BodiesDynamicsHandle(elapsedTime);
//     }

//     void PhysicsWorld::BodiesDynamicsHandle(double elapsedTime)
//     {
//         for (Body *body : _bodies)
//         {
//             body->velocity() += body->force() / body->mass() * elapsedTime;
//             body->position() += body->velocity() * elapsedTime;

//             body->force() = Vector2::zero();
//         }
//     }
// }