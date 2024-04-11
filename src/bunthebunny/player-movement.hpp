#pragma once

#include "miaangine.hpp"

#include "player.hpp"

class PlayerMovement
{
public:
    PlayerMovement(mia::Body *body);
    ~PlayerMovement();
    
private:
    mia::Body &_body;

    float _maxSpeed;
    float _groundAcceleration;
    float _groundDeceleration;
    float _groundTurnRate;
    float _onAirAcceleration;
    float _onAirDeceleration;
    float _onAirTurnRate;

    int _directionInput = 0;
    bool _jumpInput = false;
    bool _isGrounded = true; // TODO

    mia::v2f _currentVelocity;
    mia::v2f _desiredVelocity;

    const float GRAVITY = -10;

public:
    void SetDirectionInput(int input);
    void SetJumpInput(bool input);

    void Update();

private:
    void GravityApply();

    void MovingHandle();
    void JumpHandle();
    
    void ApplyVelocity();

    float GetCurrentAcceleration();
};