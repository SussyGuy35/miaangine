#include "player.hpp"

#include "player-movement.hpp"
#include "player-visual.hpp"

Player::Player(int x, int y):
    Object("Player", x, y),
    Observer(),
    _portrait(new mia::Portrait(this, nullptr, {0.5, 0.125})), // FIXME
    _body(new mia::Body(this, mia::_BODY_DYNAMIC, {.9, 1.5}, {0.5, 0})),
    _movement(new PlayerMovement(this)),
    _visual(new PlayerVisual(this))
{
    _portrait->setSprite(_visual->GetSprite());

    mia::_Renderer().RegisterPortrait(_portrait);
    mia::_Physics().RegisterBody(_body);
    mia::_Events().RegisterObserver(this);
}

Player::~Player()
{
    delete _portrait;
    delete _body;
}

mia::Portrait& Player::portrait()
{
    return *_portrait;
}
mia::Body& Player::body()
{
    return *_body;
}

void Player::Update(int message)
{
    if (message == mia::_EVENT_PRIMARY_UPDATE)
    {
        int horizontalInput = 0, verticalInput = 0;
        if (mia::_Input().getKey(SDL_SCANCODE_RIGHT)) horizontalInput += 1;
        if (mia::_Input().getKey(SDL_SCANCODE_LEFT )) horizontalInput -= 1;
        if (mia::_Input().getKey(SDL_SCANCODE_UP   )) verticalInput += 1;
        if (mia::_Input().getKey(SDL_SCANCODE_DOWN )) verticalInput -= 1;

        bool jumpInput = false;
        if (mia::_Input().getKey(SDL_SCANCODE_C)) jumpInput = true;

        bool dashInput = false;
        if (mia::_Input().getKeyDown(SDL_SCANCODE_X)) dashInput = true;

        _movement->SetInput(horizontalInput, verticalInput, jumpInput, dashInput);

        _portrait->setSprite(_visual->GetSprite());

        _movement->Update();
        _visual->Update();
    }

    if (message == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        _movement->LateUpdate();
    }
}
