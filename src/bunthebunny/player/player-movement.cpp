#include "player-movement.hpp"

#include "player.hpp"
#include "particle.hpp"

Particle *_jumpParticle;
Particle *_dashParticle;
Particle *_reGDashParticle;

PlayerMovement::PlayerMovement(Player *manager):
    _manager(*manager),
    _maxSpeed(10),

    _groundAcceleration(5),
    _groundDeceleration(6),
    _groundTurnRate(6),
    _onAirAcceleration(5),
    _onAirDeceleration(1),
    _onAirTurnRate(4),

    _jumpHeight(15),
    _gravityDragDownScale(1.5),
    _coyoteTime(0.08),
    _jumpBufferTime(0.12),

    _dashVelocityThreshhold(3),
    _dashDelay(.025),
    _initDashDuration(.15),
    _initDashMultiplier(3),
    _lateDashMultiplier(1.75),

    _state(FALLING)
{
    _jumpParticle = new Particle("D:/SDL/miaangine/asset/effect-48x48.png", {0, 48}, {48 * 3, 48}, {48, 48});
    _dashParticle = new Particle("D:/SDL/miaangine/asset/effect-48x48.png", {0, 0}, {48 * 4, 48}, {48, 48});
    _reGDashParticle = new Particle("D:/SDL/miaangine/asset/effect-48x48.png", {0, 48*2}, {48 * 4, 48}, {48, 48});
}

PlayerMovement::~PlayerMovement()
{}

Player& PlayerMovement::GetManager()
{
    return _manager;
}
int PlayerMovement::GetState()
{
    return _state;
}

void PlayerMovement::Reset()
{
    _manager.body().velocity() = mia::v2f::zero();
    _currentVelocity = mia::v2f::zero();
    _desiredVelocity = mia::v2f::zero();
    _storeVelocity = 0;
    _state = FALLING;
}

float PlayerMovement::GetSpeed()
{
    if (_state == DASHING) return _lastDashVelocity.magnitude() * _lateDashMultiplier;
    return std::abs(_manager.body().velocity().x);
}
float PlayerMovement::GetStoreSpeed()
{
    return _storeVelocity;
}
int PlayerMovement::GetMoveDirection()
{
    return _directionInput;
}
mia::v2f PlayerMovement::GetDashDirection()
{
    return _lastDashVelocity.normalize();
}

void PlayerMovement::RegainDash()
{
    _reGDashParticle->Play(_manager.position() + mia::v2f::up() * 1);
    _canDash = true;
}
void PlayerMovement::TranferVelocity(mia::v2f targetVelocity)
{
    if (targetVelocity.y > 0) _state = JUMPING;
    else _state = FALLING;

    _manager.body().velocity() = _currentVelocity = targetVelocity;
}

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

    WallJumpAvailabilityCheck();
    WallJumpHandle();

    DashHandle();

    ApplyVelocity();
}

void PlayerMovement::LateUpdate()
{

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
            ExecuteAJump(_jumpHeight);
            _coyoteTimerCount = -1;
        }
        else
        {
            _bufferTimerCount = _jumpBufferTime;
        }
    }

    if (_canJump && _bufferTimerCount >= 0) 
    {
        ExecuteAJump(_jumpHeight);
        _bufferTimerCount = -1;
    }
}
void PlayerMovement::JumpAvailabilityCheck()
{
    if (!_canJump && _isGrounded)
    {
        _jumpParticle->Play(_manager.position());
    }

    _canJump = _isGrounded && _state != DASH_PREPARE;
}
void PlayerMovement::ExecuteAJump(float force)
{
    if (_state == DASHING)
    {
        _canDash = false;
    }

    _jumpParticle->Play(_manager.position());
    _currentVelocity.y = force;
    _state = JUMPING;
}

void PlayerMovement::WallJumpHandle()
{
    if (_state == DASH_PREPARE)// || _state == DASHING)
    {
        return;
    }

    if (_wallJumpCoyoteTimerCount >= 0) _wallJumpCoyoteTimerCount -= mia::_Time().deltaTime();
    if (_wallJumpBufferTimerCount >= 0) _wallJumpBufferTimerCount -= mia::_Time().deltaTime();

    if (!_canWallJump)
    {
        if (!_wallJumpCoyoteLock) _wallJumpCoyoteTimerCount = _coyoteTime;
        _wallJumpCoyoteLock = true;
    }
    else 
    {
        _wallJumpCoyoteLock = false;
    }

    if (_jumpInput)
    {
        if (_wallJumpCoyoteTimerCount >= 0)
        {
            ExecuteAJump(_jumpHeight);
            _wallJumpCoyoteTimerCount = -1;
        }
        else
        {
            _wallJumpBufferTimerCount = _jumpBufferTime;
        }
    }

    if (_canWallJump && _wallJumpBufferTimerCount >= 0) 
    {
        ExecuteAJump(_jumpHeight);
        _wallJumpBufferTimerCount = -1;
    }
}
void PlayerMovement::WallJumpAvailabilityCheck()
{
    if (_desiredVelocity.x == 0) return;

    const float OFFSET = 0.1;
    mia::rect playerRect = _manager.body().GetRect();
    mia::rect checkRectLeft, checkRectRight;
    checkRectLeft.pos.x = playerRect.pos.x - OFFSET - OFFSET;
    checkRectRight.pos.x = playerRect.pos.x + playerRect.siz.x + OFFSET;
    checkRectLeft.pos.y = checkRectRight.pos.y = playerRect.pos.y;
    checkRectLeft.siz.x = checkRectRight.siz.x = OFFSET;
    checkRectLeft.siz.y = checkRectRight.siz.y =playerRect.siz.y;

    _canWallJump = mia::_Physics().Query(checkRectLeft) || mia::_Physics().Query(checkRectRight);
}

void PlayerMovement::DashHandle()
{
    if (!_canDash)
    {
        if (_state != DASH_PREPARE && _state != DASHING && _state != JUMPING)
        {
            if (_canJump || _canWallJump)
            {
                RegainDash();
            }
        }
    }

    if (_state == DASH_PREPARE)
    {
        if (_dashDelayTimeBound > 0 && mia::_Time().time() >= _dashDelayTimeBound)
        {
            _lastDashVelocity = _dashDirectionInput * _dashFinalSpeed;

            _currentVelocity = _lastDashVelocity * _initDashMultiplier;
            _state = DASHING;

            _dashParticle->Play(_manager.position() + mia::v2f::up() * 1);

            _dashDelayTimeBound = -1;
            _dashInitTimeBound = mia::_Time().time() + _initDashDuration;

            _canDash = false;
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

    if (_dashInput)
    {
        if (_canDash && _storeVelocity > _dashVelocityThreshhold)
        {
            _state = DASH_PREPARE;
            _dashFinalSpeed = std::max(_storeVelocity, std::abs(_currentVelocity.x) / _lateDashMultiplier);
            _currentVelocity = mia::v2f::zero();

            _dashDelayTimeBound = mia::_Time().time() + _dashDelay;
        }
        else 
        {
            _dashBufferTimerCount = _jumpBufferTime;
        }
    } 

    if (_dashBufferTimerCount >= 0) _dashBufferTimerCount -= mia::_Time().deltaTime();
    if (_canDash && _storeVelocity > _dashVelocityThreshhold && _dashBufferTimerCount >= 0)
    {
        _state = DASH_PREPARE;
        _dashFinalSpeed = std::max(_storeVelocity, std::abs(_currentVelocity.x) / _lateDashMultiplier);
        _currentVelocity = mia::v2f::zero();

        _dashDelayTimeBound = mia::_Time().time() + _dashDelay;
        _canDash = false;

        _dashBufferTimerCount = -1;
    }
}

void PlayerMovement::GroundedCheck()
{
    const float OFFSET = 0.05;
    mia::rect playerRect = _manager.body().GetRect();
    mia::rect checkRect;
    checkRect.pos.x = playerRect.pos.x;
    checkRect.pos.y = playerRect.pos.y - 2 * OFFSET;
    checkRect.siz.x = playerRect.siz.x;
    checkRect.siz.y = OFFSET;
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
        if (_state == JUMPING)
        {
            if (_currentVelocity.y < 0) _state = FALLING;
        }
        else 
        {
            _state = FALLING;
        }
    }
    else 
    {
        const float THRESHHOLDSCALE = .3;
        if (std::abs(_currentVelocity.x) > _maxSpeed * THRESHHOLDSCALE) 
        {
            _state = RUNNING;
        }
        else 
        {
            _state = STANDING;
        }
    }
}

float PlayerMovement::GetCurrentAcceleration()
{
    if (_isGrounded)
    {
        if (_desiredVelocity.x * _currentVelocity.x < 0) return _groundTurnRate * 2;
        else if (std::abs(_desiredVelocity.x) < std::abs(_currentVelocity.x)) return _groundDeceleration;
        else return _groundAcceleration;
    }
    else
    {
        if (_desiredVelocity.x * _currentVelocity.x < 0) return _onAirTurnRate * 2;
        else if (std::abs(_desiredVelocity.x) < std::abs(_currentVelocity.x)) return _onAirDeceleration;
        else return _onAirAcceleration;
    }

    return _groundAcceleration;
}