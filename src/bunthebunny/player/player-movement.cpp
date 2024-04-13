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
    _coyoteTime(0.06),
    _jumpBufferTime(0.08),

    _dashDelayTime(0.05),

    _state(FALLING)
{}

PlayerMovement::~PlayerMovement()
{}

void PlayerMovement::SetInput(int horizontalInput, int verticalInput, bool jumpInput, bool dashInput)
{
    _directionInput = horizontalInput;
    _directionInput = (_directionInput > 0) - (_directionInput < 0);

    _jumpInput = jumpInput;

    if (horizontalInput != 0 && verticalInput != 0)
        _dashDirectionInput = mia::v2f(horizontalInput, verticalInput).normalize();

    _dashInput = dashInput;
}

void PlayerMovement::Update(mia::Body &body)
{
    GroundedCheck();

    StateReCheck();

    GravityApply(body);

    MovingHandle();
    JumpHandle();

    DashHandle();

    ApplyVelocity(body);
}

void PlayerMovement::LateUpdate(mia::Body &body)
{
    _storeVelocity = std::abs(body.velocity().x);

}

void PlayerMovement::MovingHandle()
{
    if (_state == DASH_PREPARE || _state == DASHING)
    {
        return;
    }

    _desiredVelocity.x = _maxSpeed * _directionInput;

    float accelerationStep = GetCurrentAcceleration() * _maxSpeed * mia::_Time().deltaTime();
    float actualStep = accelerationStep * (_currentVelocity.x < _desiredVelocity.x ? 1 : -1);

    _currentVelocity.x += actualStep;
    if (std::min(_currentVelocity.x, _currentVelocity.x - actualStep) <= _desiredVelocity.x && 
        _desiredVelocity.x <= std::max(_currentVelocity.x, _currentVelocity.x - actualStep))
    {
        float delta = _currentVelocity.x - _desiredVelocity.x;
        _currentVelocity.x -= delta;
    }
}
void PlayerMovement::JumpHandle()
{
    if (_state == DASH_PREPARE || _state == DASHING)
    {
        return;
    }

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

void PlayerMovement::DashHandle()
{
    if (_state == DASH_PREPARE)
    {
            printf("%f\n", _dashFinalSpeed);
        if (_dashTimeBound > 0 && mia::_Time().time() >= _dashTimeBound)
        {
            DashRaw(_dashDirectionInput * _dashFinalSpeed);
            _dashTimeBound = -1;
        }

        return;
    }

    if (_state == DASHING) return; //TODO

    if (_dashInput)
    {
        _state = DASH_PREPARE;
        _currentVelocity = mia::v2f::zero();
        _dashFinalSpeed = _storeVelocity;

        _dashTimeBound = mia::_Time().time() + _dashDelayTime;
    }
}
void PlayerMovement::DashRaw(mia::v2f value)
{
    _currentVelocity = value * 2;
    _state = DASHING;
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
    if (_state == DASH_PREPARE || _state == DASHING)
    {
        return;
    }

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
    if (_state == DASH_PREPARE)
    {
        return;
    }

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
        if (_state == DASHING)
        {
            _state = FALLING;
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