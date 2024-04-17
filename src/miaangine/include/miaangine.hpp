#ifndef _MIAANGINE__
#define _MIAANGINE__

#include "common.hpp"

#include "game.hpp"
#include "input.hpp"
#include "time.hpp"
#include "event-dispatcher.hpp"
#include "sprite-handler.hpp"
#include "camera.hpp"
#include "renderer.hpp"
#include "physics.hpp"

#include "observer.hpp"
#include "object.hpp"
#include "ui.hpp"
#include "portrait.hpp"
#include "body.hpp"
#include "image.hpp"
#include "tilemap.hpp"

#include "sprite.hpp"

namespace mia
{
    inline Game& _Game()  { return Game::Instance(); }
    inline Input& _Input() { return Input::Instance(); }
    inline Time& _Time() { return Time::Instance(); }
    inline EventDispatcher& _Events() { return EventDispatcher::Instance(); }
    inline SpriteHandler& _SpriteHandler() { return SpriteHandler::Instance(); }
    inline Camera& _Camera() { return Camera::Instance(); }
    inline Renderer& _Renderer() { return Renderer::Instance(); }
    inline Physics& _Physics() { return Physics::Instance(); }
}

#endif