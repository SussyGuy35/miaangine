#include "player-movement.hpp"

PlayerMovement::PlayerMovement(Player *manager):
    _manager(*manager),
    _maxSpeed(10),

    _groundAcceleration(4),
    _groundDeceleration(6),
    _groundTurnRate(6),
    _onAirAcceleration(3),
    _onAirDeceleration(.5),
    _onAirTurnRate(3),

    _jumpHeight(15),
    _gravityDragDownScale(1.5),
    _coyoteTime(0.08),
    _jumpBufferTime(0.08),

    _dashVelocityThreshhold(3),
    _dashDelay(.05),
    _initDashDuration(.25),
    _initDashMultiplier(3.5),
    _lateDashMultiplier(2),

    _state(FALLING)
{}

PlayerMovement::~PlayerMovement()
{}

void PlayerMovement::SetInput(int horizontalInput, int verticalInput, bool jumpInput, bool dashInput)
{
    _directionInput = horizontalInput;
    _directionInput = (_directionInput > 0) - (_directionInput < 0);

    std::vector<mia::v2f> contactNormals = _manager.body().contact();
    for (mia::v2f normal : contactNormals)
    {
        if (normal.x < 0 && _directionInput > 0) _directionInput = 0.0;
        if (normal.x > 0 && _directionInput < 0) _directionInput = 0.0;
    }

    _jumpInput = jumpInput;

    if (horizontalInput != 0 || verticalInput != 0)
        _dashDirectionInput = mia::v2f(horizontalInput, verticalInput).normalize();

    _dashInput = dashInput;
}

void PlayerMovement::Update()
{
    GroundedCheck();

    StateReCheck();

    GravityApply();

    MovingHandle();

    JumpAvailabilityCheck();
    JumpHandle();

    DashHandle();

    ApplyVelocity();
}

void PlayerMovement::LateUpdate()
{
    printf("%f\n", _storeVelocity);
}

void PlayerMovement::AddStoreSpeed(float value)
{
    _storeVelocity += value;
    // TODO Add decay time
}

void PlayerMovement::MovingHandle() 
{
    // Please don't read this, i don't understand this either
    if (_state == DASH_PREPARE || _state == DASHING)
    {
        return;
    }

    float accelerationStep = GetCurrentAcceleration() * _maxSpeed * mia::_Time().deltaTime();

    _desiredVelocity.x = _maxSpeed * _directionInput;
    int sign = (_currentVelocity.x < _desiredVelocity.x) - (_currentVelocity.x > _desiredVelocity.x);
    _currentVelocity.x += accelerationStep * sign;
    if (
        std::min(_currentVelocity.x, _currentVelocity.x - accelerationStep * sign) <= _desiredVelocity.x && 
        std::max(_currentVelocity.x, _currentVelocity.x - accelerationStep * sign) >= _desiredVelocity.x 
    )
    {
        _currentVelocity.x = _desiredVelocity.x;
    }

    float storeVelocityDelta = accelerationStep * (_desiredVelocity.x != 0 ? 1 : -1);
    if (
        std::min(_totalStoreVelocityGainNormalMove, _totalStoreVelocityGainNormalMove + storeVelocityDelta) <= std::abs(_desiredVelocity.x) && 
        std::max(_totalStoreVelocityGainNormalMove, _totalStoreVelocityGainNormalMove + storeVelocityDelta) >= std::abs(_desiredVelocity.x) 
    )
    {
        storeVelocityDelta = std::abs(_desiredVelocity.x) - _totalStoreVelocityGainNormalMove;
    }
    AddStoreSpeed(storeVelocityDelta);
    _totalStoreVelocityGainNormalMove += storeVelocityDelta;
}

void PlayerMovement::JumpHandle()
{
    if (_state == DASH_PREPARE)// || _state == DASHING)
    {
        return;
    }

    if (_coyoteTimerCount >= 0) _coyoteTimerCount -= mia::_Time().deltaTime();
    if (_bufferTimerCount >= 0) _bufferTimerCount -= mia::_Time().deltaTime();

    if (!_canJump)
    {
        if (!_coyoteLock) _coyoteTimerCount = _coyoteTime;
        _coyoteLock = true;
    }
    else 
    {
        _coyoteLock = false;
    }

    if (_jumpInput)
    {
        if (_coyoteTimerCount >= 0)
        {
            ExecuteAJump();
            _coyoteTimerCount = -1;
        }
        else
        {
            _bufferTimerCount = _jumpBufferTime;
        }
    }

    if (_canJump && _bufferTimerCount >= 0) 
    {
        ExecuteAJump();
        _bufferTimerCount = -1;
    }
}
void PlayerMovement::JumpAvailabilityCheck()
{
    _canJump = _isGrounded && _state != DASH_PREPARE;
}
void PlayerMovement::ExecuteAJump()
{
    _currentVelocity.y = _jumpHeight;
    _state = JUMPING;
}

void PlayerMovement::DashHandle()
{
    if (_state == DASH_PREPARE)
    {
        if (_dashDelayTimeBound > 0 && mia::_Time().time() >= _dashDelayTimeBound)
        {
            _lastDashVelocity = _dashDirectionInput * _dashFinalSpeed;

            _currentVelocity = _lastDashVelocity * _initDashMultiplier;
            _state = DASHING;

            _dashDelayTimeBound = -1;
            _dashInitTimeBound = mia::_Time().time() + _dashDelay;
        }

        return;
    }

    if (_state == DASHING) 
    {
        if (_dashInitTimeBound > 0 && mia::_Time().time() >= _dashInitTimeBound)
        {
            _currentVelocity = _lastDashVelocity * _lateDashMultiplier;
            _state = FALLING;

            _dashInitTimeBound = -1;
        }

        return;
    }

    if (_dashInput && _storeVelocity > _dashVelocityThreshhold)
    {
        _state = DASH_PREPARE;
        _currentVelocity = mia::v2f::zero();
        _dashFinalSpeed = _storeVelocity;

        _dashDelayTimeBound = mia::_Time().time() + _dashDelay;
    }
}

void PlayerMovement::GroundedCheck()
{
    mia::rect playerRect = _manager.body().GetRect();
    mia::rect checkRect;
    checkRect.pos.x = playerRect.pos.x;
    checkRect.pos.y = playerRect.pos.y - .002;
    checkRect.siz.x = playerRect.siz.x;
    checkRect.siz.y = 0.001;
    _isGrounded = ( mia::_Physics().Query(checkRect) && _currentVelocity.y <= 0 );
}

void PlayerMovement::GravityApply()
{
    if (_state == DASH_PREPARE || _state == DASHING)
    {
        return;
    }

    _currentVelocity.y = _manager.body().velocity().y;
    if (_currentVelocity.y < 0)
    {
        _manager.body().AddAcceleration(0, GRAVITY * _gravityDragDownScale);
        // _currentVelocity.y += GRAVITY * _gravityDragDownScale * mia::_Time().deltaTime();
    }
    else 
    {
        _manager.body().AddAcceleration(0, GRAVITY);
        // _currentVelocity.y += GRAVITY * mia::_Time().deltaTime();
    }
}

void PlayerMovement::ApplyVelocity()
{
    _manager.body().velocity() = _currentVelocity;
}

void PlayerMovement::StateReCheck()
{
    if (_state == DASH_PREPARE || _state == DASHING)
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