#include "miaangine.hpp"

class Bird : public mia::WorldObject
{
public:
    Bird(float x, float y);

    void Update(uint8_t message) override;

private:
    const float GRAVITY = .3;
    float acceleration = 0.0;

};