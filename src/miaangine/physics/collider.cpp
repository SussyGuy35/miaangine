// #include "collider.hpp"

// #include "core/engine-components.hpp"

// namespace mia
// {
//     Collider::Collider(Vector2 size, Vector2 offset):
//         _ucName("unclaimed"),
//         _ucPosition(Vector2::zero()),
//         _size(size),
//         _offset(offset),
//         _body(nullptr),
//         _master(nullptr)
//     {}
//     Collider::Collider(float sx, float sy, float ox, float oy):
//         _ucName("unclaimed"),
//         _ucPosition(Vector2::zero()),
//         _size(Vector2(sx, sy)),
//         _offset(Vector2(ox, oy)),
//         _body(nullptr),
//         _master(nullptr)
//     {}

//     Collider::~Collider()
//     {}

//     #pragma region Non-const attributes
//     string& Collider::name()
//     {
//         return (!_master ? _ucName : _master->name);
//     }
//     Vector2& Collider::position()
//     {
//         return (!_master ? _ucPosition : _master->position());
//     }
//     Vector2& Collider::size()
//     {
//         return _size;
//     }
//     Vector2& Collider::offset()
//     {
//         return _offset;
//     }
//     Body* Collider::body()
//     {
//         if (!_body) 
//         {
//             mia::debug.Error("[Collider(%s)] access denied: [body] Null reference; Return null. ", name().str());
//         }

//         return _body;
//     }
//     WorldObject* Collider::master()
//     {
//         if (!_master) 
//         {
//             mia::debug.Error("[Collider(%s)] access denied: [master] Null reference;  Return null. ", name().str());
//         }

//         return _master;
//     }
//     #pragma endregion

//     #pragma region Const attributes
//     const string& Collider::name() const
//     {
//         return (!_master ? _ucName : _master->name);
//     }
//     const Vector2& Collider::position() const
//     {
//         return (!_master ? _ucPosition : _master->position());
//     }
//     const Vector2& Collider::size() const
//     {
//         return _size;
//     }
//     const Vector2& Collider::offset() const
//     {
//         return _offset;
//     }
//     const Body* Collider::body() const
//     {
//         if (!_body) 
//         {
//             mia::debug.Error("[Collider(%s)] access denied: [body] Null reference; Return null. ", name().str());
//         }

//         return _body;
//     }
//     const WorldObject* Collider::master() const
//     {
//         if (!_master) 
//         {
//             mia::debug.Error("[Collider(%s)] access denied: [master] Null reference; Return null. ", name().str());
//         }

//         return _master;
//     }
//     #pragma endregion

//     const Vector2 Collider::cornerMin() const
//     {
//         return position() + _offset;
//     }
//     const Vector2 Collider::cornerMax() const
//     {
//         return position() + _offset + _size;
//     }

//     bool Collider::CheckColliding(Collider *other)
//     {
//         return (
//             cornerMin().x <= other->cornerMax().x &&
//             cornerMax().x >= other->cornerMin().x &&
//             cornerMin().y <= other->cornerMax().y &&
//             cornerMax().y >= other->cornerMin().y
//         );
//     }

//     void Collider::ShiftBody(Body *body)
//     {
//         this->_body = body;
//     }
//     void Collider::ShiftMaster(WorldObject *master)
//     {
//         this->_master = master;
//     }
// }