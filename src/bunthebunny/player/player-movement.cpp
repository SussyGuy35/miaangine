#include "player-movement.hpp"

PlayerMovement::PlayerMovement(Player *manager):
    _manager(manager),
    _maxSpeed(10),
    _groundAcceleration(5),
    _groundDeceleration(2),
    _groundTurnRate(2),
    _onAirAcceleration(2),
    _onAirDeceleration(2),
    _onAirTurnRate(2),
    _jumpHeight(20),
    _gravityDragDownScale(1.5)
{}

PlayerMovement::~PlayerMovement()
{}

void PlayerMovement::SetInput(int directionInput, bool jumpInput)
{
    _directionInput = directionInput;
    _directionInput = (_directionInput > 0) - (_directionInput < 0);

    _jumpInput = jumpInput;
}

void PlayerMovement::Update(mia::Body &body)
{
    GroundedCheck();

    GravityApply();

    MovingHandle();
    JumpHandle();

    ApplyVelocity(body);
}

void PlayerMovement::MovingHandle()
{
    _desiredVelocity.x = _maxSpeed * _directionInput;

    float accelerationStep = GetCurrentAcceleration() * _maxSpeed * mia::_Time().deltaTime();
    float actualStep = accelerationStep * (_currentVelocity.x < _desiredVelocity.x ? 1 : -1);

    _currentVelocity.x += actualStep;
    if (std::min(_currentVelocity.x, _currentVelocity.x - actualStep) <= _desiredVelocity.x && 
        _desiredVelocity.x <= std::max(_currentVelocity.x, _currentVelocity.x - actualStep))
    {
        _currentVelocity.x = _desiredVelocity.x;
    }
}
void PlayerMovement::JumpHandle()
{
    if (_jumpInput)
    {
        if (_isGrounded) _currentVelocity.y = _jumpHeight;
    }
}

void PlayerMovement::GroundedCheck()
{
    mia::rect playerRect = _manager->body().GetRect();
    mia::rect checkRect;
    checkRect.pos.x = playerRect.pos.x;
    checkRect.pos.y = playerRect.pos.y - .002;
    checkRect.siz.x = playerRect.siz.x;
    checkRect.siz.y = 0.001;
    _isGrounded = ( mia::_Physics().Query(checkRect) && _currentVelocity.y <= 0 );
}

void PlayerMovement::GravityApply()
{
    if (_currentVelocity.y < 0)
    {
        _currentVelocity.y += GRAVITY * _gravityDragDownScale * mia::_Time().deltaTime();
    }
    else 
    {
        _currentVelocity.y += GRAVITY * mia::_Time().deltaTime();
    }
}

void PlayerMovement::ApplyVelocity(mia::Body &body)
{
    body.velocity() = _currentVelocity;
}

float PlayerMovement::GetCurrentAcceleration()
{
    if (_isGrounded)
    {
        if (_desiredVelocity.x == 0) return _groundDeceleration;
        else if (_desiredVelocity.x * _currentVelocity.x < 0) return _groundTurnRate * 2;
        else return _groundAcceleration;
    }
    else
    {
        if (_desiredVelocity.x == 0) return _onAirDeceleration;
        else if (_desiredVelocity.x * _currentVelocity.x < 0) return _onAirTurnRate * 2;
        else return _onAirAcceleration;
    }

    return _groundAcceleration;
}