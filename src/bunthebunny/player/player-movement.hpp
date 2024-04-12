#pragma once

#include "miaangine.hpp"

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

    int _state;

    int _directionInput = 0;
    bool _jumpInput = false;
    bool _isGrounded = true; // TODO
    float _coyoteTimeBound = -1;
    bool _coyoteLock = false;
    float _bufferTimeBound = -1;

    mia::v2f _currentVelocity;
    mia::v2f _desiredVelocity;

    const float GRAVITY = -40;

public:
    void SetInput(int directionInput, bool jumpInput);

    void Update(mia::Body &body);

private:
    void MovingHandle();
    void JumpHandle();
    void JumpRaw();

    void GroundedCheck();
    void GravityApply(const mia::Body &body);

    void ApplyVelocity(mia::Body &body);

    void StateReCheck();

    float GetCurrentAcceleration();
};