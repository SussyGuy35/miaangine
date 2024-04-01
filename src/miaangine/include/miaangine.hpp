#ifndef _MIAANGINE__
#define _MIAANGINE__

#include "common.hpp"

#include "game.hpp"
#include "input.hpp"
#include "sprite-handler.hpp"
#include "camera.hpp"

#include "world-object.hpp"
#include "portrait.hpp"

#include "sprite.hpp"

namespace mia
{
    inline Game& _Game()  { return Game::Instance(); }
    inline Input& _Input() { return Input::Instance(); }
    inline SpriteHandler& _SpriteHandler() { return SpriteHandler::Instance(); }
    inline Camera& _Camera() { return Camera::Instance(); }
}

#endif