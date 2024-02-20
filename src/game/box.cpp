#include "miaangine.hpp"

class Box : public mia::IEventListener
{
    void Update() override
    {
        printf("A");
    }
};