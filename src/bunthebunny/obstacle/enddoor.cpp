#include "enddoor.hpp"

#include "game-manager.hpp"

const float HEIGHT = 3;
const float WIDTH = 2;

Enddoor::Enddoor(Player *player, mia::v2f position):
    Obstacle(position),
    _portrait(new mia::Portrait(this, nullptr)),
    _player(*player)
{
    this->position() = position;

    mia::_SpriteHandler().SetSource("./../asset/door-32x48.png");
    _portrait->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {32, 48}));
}

Enddoor::~Enddoor() = default;

mia::rect Enddoor::GetRect() const 
{
    mia::rect res;
    res.pos = position();
    res.siz.x = WIDTH;
    res.siz.y = HEIGHT;
    return res;
}

void Enddoor::Update(int massage)
{
    if (massage == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        if (GetRect().overlap(_player.body().GetRect()))
        {
            mia::_Audio().Play(5);
            GameManager::Instance().ReloadLevel();
        }
    }
}

void Enddoor::Activate()
{
    mia::_Renderer().RegisterPortrait(&portrait());
    mia::_Events().RegisterObserver(this);
}
void Enddoor::DeActivate()
{
    mia::_Renderer().UnregisterPortrait(&portrait());
    mia::_Events().RemoveObserver(this);
}