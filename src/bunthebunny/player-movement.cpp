#include "player-movement.hpp"

PlayerMovement::PlayerMovement(mia::Body *body):
    _body(*body),
    _maxSpeed(10),
    _groundAcceleration(10),
    _groundDeceleration(2),
    _groundTurnRate(2),
    _onAirAcceleration(1),
    _onAirDeceleration(1),
    _onAirTurnRate(1),
    _jumpHeight(20),
    _gravityDragDownScale(1.5)
{}

PlayerMovement::~PlayerMovement()
{}

void PlayerMovement::SetDirectionInput(int input)
{
    _directionInput = input;
    _directionInput = (_directionInput > 0) - (_directionInput < 0);
}
void PlayerMovement::SetJumpInput(bool input)
{
    _jumpInput = input;
}

void PlayerMovement::Update()
{
    GravityApply();

    MovingHandle();
    JumpHandle();

    ApplyVelocity();
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
        if (_currentVelocity.y <= 0) _currentVelocity.y = _jumpHeight;
    }

    // if (_currentVelocity.y)
    // {

    // }
}

void PlayerMovement::GroundedCheck()
{
    mia::rect checkRect;
    // checkRect.x = 
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

void PlayerMovement::ApplyVelocity()
{
    _body.velocity() = _currentVelocity;
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