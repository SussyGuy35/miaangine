#pragma once

#include "miaangine.hpp"

#include "player.hpp"

class PlayerMovement
{
public:
    PlayerMovement(Player *manager);
    ~PlayerMovement();
    
private:
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

    int _directionInput = 0;
    bool _jumpInput = false;
    bool _isGrounded = true; // TODO

    mia::v2f _currentVelocity;
    mia::v2f _desiredVelocity;

    const float GRAVITY = -40;

public:
    void SetInput(int directionInput, bool jumpInput);

    void Update(mia::Body &body);

private:
    void MovingHandle();
    void JumpHandle();

    void GroundedCheck();
    void GravityApply();

    void ApplyVelocity(mia::Body &body);

    float GetCurrentAcceleration();
};