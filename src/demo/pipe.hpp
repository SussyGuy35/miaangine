#include "miaangine.hpp"

class Pipe : public mia::WorldObject
{
public:
    Pipe(float x, float y);

    void Update(uint8_t message) override;
};