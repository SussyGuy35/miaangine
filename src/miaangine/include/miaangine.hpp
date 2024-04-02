#ifndef _MIAANGINE__
#define _MIAANGINE__

#include "common.hpp"

#include "game.hpp"
#include "input.hpp"
#include "time.hpp"
#include "sprite-handler.hpp"
#include "camera.hpp"

#include "object.hpp"
#include "transform.hpp"
#include "portrait.hpp"

#include "sprite.hpp"

namespace mia
{
    inline Game& _Game()  { return Game::Instance(); }
    inline Input& _Input() { return Input::Instance(); }
    inline Time& _Time() { return Time::Instance(); }
    inline SpriteHandler& _SpriteHandler() { return SpriteHandler::Instance(); }
    inline Camera& _Camera() { return Camera::Instance(); }
}

#endif