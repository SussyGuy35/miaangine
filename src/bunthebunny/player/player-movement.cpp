#include "player-movement.hpp"

PlayerMovement::PlayerMovement(Player *manager):
    _manager(manager),
    _maxSpeed(10),
    _groundAcceleration(10),
    _groundDeceleration(5),
    _groundTurnRate(5),
    _onAirAcceleration(2),
    _onAirDeceleration(5),
    _onAirTurnRate(5),
    _jumpHeight(15),
    _gravityDragDownScale(1.5),
    _coyoteTime(.06),
    _jumpBufferTime(.08),
    _state(FALLING)
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

    StateReCheck();

    GravityApply(body);

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
    if (!_isGrounded)
    {
        if (!_coyoteLock && _state != JUMPING)
        {
            _coyoteTimeBound = mia::_Time().time() + _coyoteTime;
        }
        _coyoteLock = true;
    }
    else 
    {
        _coyoteLock = false;
    }
    printf("%d\n", _coyoteLock);

    if (_jumpInput)
    {
        if (mia::_Time().time() <= _coyoteTimeBound)
        {
            JumpRaw();
            _coyoteTimeBound = -1;
        }
        else
        {
            _bufferTimeBound = mia::_Time().time() + _jumpBufferTime;
        }
    }

    if (_isGrounded && (mia::_Time().time() <= _bufferTimeBound)) 
    {
        _bufferTimeBound = -1;
        JumpRaw();
    }
}

void PlayerMovement::JumpRaw()
{
    _currentVelocity.y = _jumpHeight;
    _state = JUMPING;
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

void PlayerMovement::GravityApply(const mia::Body &body)
{
    _currentVelocity.y = body.velocity().y;
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

void PlayerMovement::StateReCheck()
{
    if (!_isGrounded) 
    {
        if (_state == STANDING) 
        {
            _state = FALLING;
        }
        if (_state == JUMPING)
        {
            if (_currentVelocity.y < 0) _state = FALLING;
        }
    }
    else 
    {
        _state = STANDING;
    }
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