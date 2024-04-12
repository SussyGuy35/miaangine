#include "player.hpp"

#include "player-movement.hpp"

Player::Player(int x, int y):
    Object("Player", x, y),
    Observer(),
    _portrait(nullptr), // FIXME
    _body(new mia::Body(this, mia::_BODY_DYNAMIC, {1, 1.5}, {0, 0.5})),
    _movement(new PlayerMovement(_body))
{
    mia::_Physics().RegisterBody(_body);
    mia::_Events().RegisterObserver(this);
}

Player::~Player()
{
    delete _portrait;
    delete _body;
}

void Player::Update(int message)
{
    if (message == mia::_EVENT_PRIMARY_UPDATE)
    {
        int horizontalInput = 0;
        if (mia::_Input().getKey(SDL_SCANCODE_RIGHT)) horizontalInput += 1;
        if (mia::_Input().getKey(SDL_SCANCODE_LEFT )) horizontalInput -= 1;
        _movement->SetDirectionInput(horizontalInput);

        bool jumpInput = false;
        if (mia::_Input().getKey(SDL_SCANCODE_C)) jumpInput = true;
        _movement->SetJumpInput(jumpInput);

        _movement->Update();
    }
}
