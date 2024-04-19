#include "box.hpp"

Box::Box(float x, float y, float sx, float sy):
    Object("Box", x, y),
    _body(new mia::Body(this, mia::_BODY_STATIC, {sx, sy}))
{
    mia::_Physics().RegisterBody(_body);
}

Box::~Box()
{
    
}

