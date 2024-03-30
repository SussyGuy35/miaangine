#ifndef _MIAANGINE__
#define _MIAANGINE__

#include "common.hpp"

#include "game.hpp"
#include "input.hpp"

#include "world-object.hpp"

namespace mia
{
    inline Game&  _Game()  { return Game::Instance(); }
    inline Input& _Input() { return Input::Instance(); }
}

#endif