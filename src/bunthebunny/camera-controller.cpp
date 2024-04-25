#include "camera-controller.hpp"

CamaraController::CamaraController(Player *player):
    _player(player),
    leftBound(0),
    rightBound(0),
    idealPlayerOffset(0),
    camFollowingBound(0),
    _smooth(5)
{
    mia::_Events().RegisterObserver(this);
}

CamaraController::~CamaraController()
{}

void CamaraController::Update(int message)
{
    if (message == mia::_EVENT_PRIMARY_UPDATE)
    {
        if (std::abs(_player->position().x - (mia::_Camera().position().x + mia::_Camera().getCameraWidth() / 2)) > camFollowingBound)
        {
            _following = true;
        }

        if (_following)
        {
            float targetPos = _player->position().x + idealPlayerOffset - mia::_Camera().getCameraWidth() / 2;

            mia::_Camera().position().x = mia::_Camera().position().x + (targetPos - mia::_Camera().position().x) * _smooth * mia::_Time().deltaTime();

            if (std::abs(targetPos - mia::_Camera().position().x) < 0.05) _following = false;
        }

        if (mia::_Camera().position().x < leftBound) mia::_Camera().position().x = leftBound;
        if (mia::_Camera().position().x + mia::_Camera().getCameraWidth() > rightBound) mia::_Camera().position().x = rightBound - mia::_Camera().getCameraWidth();
    }
}