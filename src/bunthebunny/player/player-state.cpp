#include "player-state.hpp"

PlayerState::PlayerState()
{}

PlayerState::~PlayerState()
{}

void PlayerState::SetPlayerRect(mia::rect rect)
{
    _playerRect = rect;
}

void PlayerState::UpdateTouchCheck()
{
    _touchCheck[0] = mia::_Physics().Query(_playerRect.pos.x, _playerRect.pos.y - .01, _playerRect.siz.x, .01); // Down
    _touchCheck[1] = mia::_Physics().Query(_playerRect.pos.x, _playerRect.pos.y - .01, _playerRect.siz.x, .01); // Right
    _touchCheck[2] = mia::_Physics().Query(_playerRect.pos.x, _playerRect.pos.y - .01, _playerRect.siz.x, .01); // Left
    _touchCheck[3] = mia::_Physics().Query(_playerRect.pos.x, _playerRect.pos.y - .01, _playerRect.siz.x, .01); // Up
}