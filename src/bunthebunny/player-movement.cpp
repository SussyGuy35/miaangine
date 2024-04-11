#include "player-movement.hpp"

PlayerMovement::PlayerMovement(mia::Body *body):
    _body(*body),
    _maxSpeed(100),
    _groundAcceleration(1),
    _groundDeceleration(.5),
    _groundTurnRate(.5),
    _onAirAcceleration(1),
    _onAirDeceleration(1),
    _onAirTurnRate(1)
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

void PlayerMovement::GravityApply()
{
    _currentVelocity.y += GRAVITY * mia::_Time().deltaTime();
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