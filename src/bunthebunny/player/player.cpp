#include "player.hpp"

#include "player-movement.hpp"
#include "player-visual.hpp"
#include "player-ui.hpp"

#include "game-manager.hpp"

Player::Player(float x, float y):
    Object("Player", x, y),
    Observer(),
    _active(false),
    _portrait(new mia::Portrait(this, nullptr, {0.5, 0.125})), // FIXME
    _body(new mia::Body(this, mia::_BODY_DYNAMIC, {.9, 1.5}, {0.5, 0})),
    _movement(new PlayerMovement(this)),
    _visual(new PlayerVisual(this)),
    _ui(new PlayerUI(this))
{
    mia::_Events().RegisterObserver(this);
    // Activate();
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

PlayerMovement& Player::movement()
{
    return *_movement;
}
PlayerVisual& Player::visual()
{
    return *_visual;
}
PlayerUI& Player::ui()
{
    return *_ui;
}

void Player::Update(int message)
{
    if (!_active) return;
    if (message == mia::_EVENT_PRIMARY_UPDATE)
    {
        if (mia::_Input().getKeyDown(SDL_SCANCODE_R)) GameManager::Instance().ReloadLevel();
        if (mia::_Input().getKeyDown(SDL_SCANCODE_ESCAPE)) GameManager::Instance().LoadMainMenu();

        int horizontalInput = 0, verticalInput = 0;
        if (mia::_Input().getKey(SDL_SCANCODE_RIGHT)) horizontalInput += 1;
        if (mia::_Input().getKey(SDL_SCANCODE_LEFT )) horizontalInput -= 1;
        if (mia::_Input().getKey(SDL_SCANCODE_UP   )) verticalInput += 1;
        if (mia::_Input().getKey(SDL_SCANCODE_DOWN )) verticalInput -= 1;

        bool jumpInput = false;
        if (mia::_Input().getKeyDown(SDL_SCANCODE_C)) jumpInput = true;

        bool dashInput = false;
        if (mia::_Input().getKeyDown(SDL_SCANCODE_X)) dashInput = true;

        _movement->SetInput(horizontalInput, verticalInput, jumpInput, dashInput);

        _movement->Update();
        _visual->Update();
        _ui->Update();
    }

    if (message == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        _movement->LateUpdate();
    }
}

void Player::Activate()
{
    if (_active) return;
    _active = true;

    _ui->Activate();

    mia::_Renderer().UnregisterPortrait(_portrait);
    mia::_Physics().UnregisterBody(_body);
    mia::_Renderer().RegisterPortrait(_portrait);
    mia::_Physics().RegisterBody(_body);
}

void Player::DeActivate()
{
    if (!_active) return;
    _active = false;

    _movement->Reset();
    _visual->Reset();
    _ui->DeActivate();

    mia::_Renderer().UnregisterPortrait(_portrait);
    mia::_Physics().UnregisterBody(_body);
}