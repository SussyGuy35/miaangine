#pragma once

#include "miaangine.hpp"

#include "player.hpp"

class PlayerMovement
{
public:
    PlayerMovement();
    ~PlayerMovement();
    
private:
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

    int _directionInput = 0;
    bool _jumpInput = false;
    bool _isGrounded = true; // TODO

    mia::v2f _currentVelocity;
    mia::v2f _desiredVelocity;

    const float GRAVITY = -40;

public:
    void SetDirectionInput(int input);
    void SetJumpInput(bool input);

    void Update(mia::Body &body);

private:
    void MovingHandle();
    void JumpHandle();

    void GroundedCheck();
    void GravityApply();

    void ApplyVelocity(mia::Body &body);

    float GetCurrentAcceleration();
};