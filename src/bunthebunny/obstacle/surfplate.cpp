#include "surfplate.hpp"

const float HEIGHT = .5;
const float WIDTH = .925;

float _surfcooldownTimerCount = -1;

Surfplate::Surfplate(Player *player, mia::v2f position):
    Obstacle(position),
    _player(*player),
    _portrait(new mia::Portrait(this, nullptr)),
    _additionalSpeed(5), // FIXME
    _cooldown(.5)
{
    this->position() = position;

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/obstacles-16x16.png");
    _portrait->setSprite(mia::_SpriteHandler().MakeCut({16*3, 0}, {16, 16}));
}

Surfplate::~Surfplate() = default;

mia::rect Surfplate::GetRect() const 
{
    mia::rect res;
    res.pos = position();
    res.siz.x = WIDTH;
    res.siz.y = HEIGHT;
    return res;
}

void Surfplate::Update(int massage)
{
    if (massage == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        if (!_active)
        {
            _surfcooldownTimerCount -= mia::_Time().deltaTime();

            if (_surfcooldownTimerCount <= 0) _active = true;
        }
        else 
        {
            if (GetRect().overlap(_player.body().GetRect()))
            {
                _player.movement().AddTemporaryStoreSpeed(_additionalSpeed);
                _player.movement().TranferVelocity(mia::v2f::right() * (_player.movement().GetStoreSpeed() + _additionalSpeed + _player.movement().GetSpeed()));
                _player.movement().RegainDash();

                _active = false;
                _surfcooldownTimerCount = _cooldown;
            }
        }
    }
}

void Surfplate::Activate()
{
    mia::_Renderer().RegisterPortrait(_portrait);
    mia::_Events().RegisterObserver(this);
}
void Surfplate::DeActivate()
{
    mia::_Renderer().UnregisterPortrait(_portrait);
    mia::_Events().RemoveObserver(this);
}