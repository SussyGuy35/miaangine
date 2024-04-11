#include "physics.hpp"

#include "renderer.hpp"

namespace mia
{
#pragma region Constructor Destructor
    Physics::Physics():
        _bodiesList(std::vector<Body*>())
    {}

    Physics::~Physics()
    {}
#pragma endregion

#pragma region Public method
    void Physics::RegisterBody(Body *body)
    {
        _bodiesList.push_back(body);
    }

    void Physics::UnregisterBody(Body *body)
    {
        auto bodyIterator = std::find(_bodiesList.begin(), _bodiesList.end(), body);

        if (bodyIterator != _bodiesList.end())
        {
            _bodiesList.erase(bodyIterator);
        }
    }

    const std::vector<Body*> Physics::GetBodiesList()
    {
        return _bodiesList;
    }

    void Physics::Update(double elapsedTime)
    {
        for (Body *body : _bodiesList) ApplyForceToBody(body);

        
    }
#pragma endregion

#pragma region Private method
    void Physics::ApplyForceToBody(Body* body)
    {
        body->velocity() += body->force() / body->mass();
        body->force() = v2f::zero();
    }
#pragma endregion
}