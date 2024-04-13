#pragma once

#include "player.hpp"

class PlayerMovement
{
public:
    PlayerMovement(Player *manager);
    ~PlayerMovement();
    
private:
    enum PlayerMovementState
    {
        STANDING,
        JUMPING,
        FALLING,
        DASH_PREPARE,
        DASHING
    };

    Player *_manager;

    float _maxSpeed;
    float _groundAcceleration;
    float _groundDeceleration;
    float _groundTurnRate;
    float _onAirAcceleration;
    float _onAirDeceleration;
    float _onAirTurnRate;

    float _jumpHeight;
    float _gravityDragDownScale;
    float _coyoteTime;
    float _jumpBufferTime;
    
    float _dashDelayTime;

    int _state;

    bool _isGrounded = true;
    float _storeVelocity = 0;

    int _directionInput = 0;
    bool _jumpInput = false;
    mia::v2f _dashDirectionInput = mia::v2f::zero();
    bool _dashInput = false;

    //Jump help
    float _coyoteTimeBound = -1;
    bool _coyoteLock = false;
    float _bufferTimeBound = -1;
    // Dash
    float _dashFinalSpeed = 0;
    float _dashTimeBound = -1;

    mia::v2f _currentVelocity;
    mia::v2f _desiredVelocity;

    const float GRAVITY = -40;

public:
    void SetInput(int horizontalInput, int verticalInput, bool jumpInput, bool dashInput);

    void Update(mia::Body &body);
    void LateUpdate(mia::Body &body);

private:
    void MovingHandle();
    void JumpHandle();
    void JumpRaw();
    void DashHandle();
    void DashRaw(mia::v2f value);

    void GroundedCheck();
    void GravityApply(const mia::Body &body);

    void ApplyVelocity(mia::Body &body);

    void StateReCheck();

    float GetCurrentAcceleration();
};