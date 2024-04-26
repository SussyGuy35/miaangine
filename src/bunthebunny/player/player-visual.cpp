#include "player-visual.hpp"

#include "player.hpp"
#include "player-movement.hpp"

PlayerVisual::PlayerVisual(Player *manager):
    _manager(*manager),
    _idleAnimation(mia::Clip()),
    _runAnimation(mia::Clip()),
    _currentClip(&_idleAnimation)
{
    _idleAnimation.MakeAnimation("./../asset/Character-48x48.png", {0, 0}, {48 * 8, 48}, {48, 48});
    _runAnimation.MakeAnimation("./../asset/Character-48x48.png", {0, 48}, {48 * 8, 48}, {48, 48});
    _jumpAnimation.MakeAnimation("./../asset/Character-48x48.png", {0, 48*2}, {48, 48}, {48, 48});
    _fallAnimation.MakeAnimation("./../asset/Character-48x48.png", {48*2, 48*2}, {48, 48}, {48, 48});
    for (int i = 0; i < 5; i++)
    {
        _dashAnimation[i].MakeAnimation("./../asset/Character-48x48.png", {48*i, 48*3}, {48, 48}, {48, 48});
    }
}

PlayerVisual::~PlayerVisual()
{
    _idleAnimation.DestroyAllSprite();
    _runAnimation.DestroyAllSprite();
}

Player& PlayerVisual::GetManager()
{
    return _manager;
}

void PlayerVisual::Reset()
{
    _currentClip = &_idleAnimation;
    _frameTimer = _timePerFrame;
}

void PlayerVisual::Update()
{
    PlayCurrentAnimation();

    switch (_manager.movement().GetState())
    {
    case PlayerMovementState::STANDING:
        _currentClip = &_idleAnimation;
        break;

    case PlayerMovementState::RUNNING:
        _currentClip = &_runAnimation;
        break;

    case PlayerMovementState::JUMPING:
        _currentClip = &_jumpAnimation;
        break;

    case PlayerMovementState::FALLING:
        _currentClip = &_fallAnimation;
        break;

    case PlayerMovementState::DASH_PREPARE:
    case PlayerMovementState::DASHING:
        {
            mia::v2f dashDir = _manager.movement().GetDashDirection();
            dashDir.x = std::abs(dashDir.x);

            if (dashDir == mia::v2f(0, 1).normalize())
                _currentClip = &_dashAnimation[0];
            if (dashDir == mia::v2f(1, 1).normalize())
                _currentClip = &_dashAnimation[1];
            if (dashDir == mia::v2f(1, 0).normalize())
                _currentClip = &_dashAnimation[2];
            if (dashDir == mia::v2f(1, -1).normalize())
                _currentClip = &_dashAnimation[3];
            if (dashDir == mia::v2f(0, -1).normalize())
                _currentClip = &_dashAnimation[4];
        }
        // TODO
        break;

    default:
        _currentClip = &_idleAnimation;
        break;
    }

    UpdatePortrait();
}

void PlayerVisual::PlayCurrentAnimation()
{
    _frameTimer -= mia::_Time().deltaTime();

    if (_frameTimer <= 0)
    {
        _currentClip->NextSprite();
        _frameTimer = _timePerFrame;
    }
}

void PlayerVisual::UpdatePortrait()
{
    _manager.portrait().setSprite(_currentClip->GetCurrentSprite());

    int moveDir = _manager.movement().GetMoveDirection();
    if (moveDir != 0)
    {
        if (moveDir < 0) _manager.portrait().flip() = SDL_FLIP_HORIZONTAL;
        else             _manager.portrait().flip() = SDL_FLIP_NONE;
    }
}