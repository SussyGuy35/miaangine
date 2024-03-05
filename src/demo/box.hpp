#include "miaangine.hpp"

class Box : public mia::WorldObject
{
public:
    Box(float x, float y);

    void Update(uint8_t message) override;

    bool fall = false;
};