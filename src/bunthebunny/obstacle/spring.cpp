#include "spring.hpp"

const float HEIGHT = .5;
const float WIDTH = .925;

float _cooldownTimerCount = -1;

Spring::Spring(Player *player, mia::v2f position):
    Obstacle(position),
    _player(*player),
    _portrait(new mia::Portrait(this, nullptr)),
    _additionalSpeed(3), // FIXME
    _cooldown(.5)
{
    this->position() = position;

    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/obstacles-16x16.png");
    _unuseSprite = mia::_SpriteHandler().MakeCut({16*2, 0}, {16, 16});
    _useSprite = mia::_SpriteHandler().MakeCut({16*2, 16}, {16, 16});

    _portrait->setSprite(_unuseSprite);
    mia::_Renderer().RegisterPortrait(_portrait);

    mia::_Events().RegisterObserver(this);
}

Spring::~Spring() = default;

mia::rect Spring::GetRect() const 
{
    mia::rect res;
    res.pos = position();
    res.siz.x = WIDTH;
    res.siz.y = HEIGHT;
    return res;
}

void Spring::Update(int massage)
{
    if (massage == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        if (!_active)
        {
            _cooldownTimerCount -= mia::_Time().deltaTime();

            if (_cooldownTimerCount <= 0) 
            {
                _active = true;
                _portrait->setSprite(_unuseSprite);
            }
        }
        else 
        {
            if (GetRect().overlap(_player.body().GetRect()))
            {
                _player.movement().AddTemporaryStoreSpeed(_additionalSpeed);
                _player.movement().TranferVelocity(mia::v2f::up() * std::max(_additionalSpeed * 5, (_player.movement().GetStoreSpeed() + _player.movement().GetSpeed())));
                _player.movement().RegainDash();

                _portrait->setSprite(_useSprite);
                _active = false;
                _cooldownTimerCount = _cooldown;
            }
        }
    }
}

void Spring::Activate()
{
    mia::_Renderer().RegisterPortrait(&portrait());
    mia::_Events().RegisterObserver(this);
}
void Spring::DeActivate()
{
    mia::_Renderer().UnregisterPortrait(&portrait());
    mia::_Events().RemoveObserver(this);
}