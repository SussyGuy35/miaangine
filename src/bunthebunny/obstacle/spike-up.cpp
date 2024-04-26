#include "spike-up.hpp"

const float HEIGHT = .1;
const float WIDTH = .925;

UpSpike::UpSpike(Player *player, mia::v2f position, int size):
    Obstacle(position),
    _player(*player),
    _size(size), 
    _additionalSpeed(3), // FIXME
    _cooldown(.5)
{
    this->position() = position;

    mia::_SpriteHandler().SetSource("./../asset/obstacles-16x16.png");
    mia::Sprite *sprite = mia::_SpriteHandler().MakeCut({0, 0}, {16, 16});

    for (int i = 0; i < size; i++)
    {
        mia::Portrait *portrait = new mia::Portrait(this, sprite, {0, 0}, {(float)0.925 * i, 0});
        mia::_Renderer().RegisterPortrait(portrait);
    }

    mia::_Events().RegisterObserver(this);
}

UpSpike::~UpSpike() = default;

mia::rect UpSpike::GetRect() const 
{
    mia::rect res;
    res.pos = position();
    res.siz.x = WIDTH * _size;
    res.siz.y = HEIGHT;
    return res;
}

void UpSpike::Update(int massage)
{
    if (massage == mia::_EVENT_AFTER_PHYSICS_CALCULATION)
    {
        if (GetRect().overlap(_player.body().GetRect()))
        {
            // TODO
        }
    }
}

void UpSpike::Activate()
{
    mia::_Renderer().RegisterPortrait(&portrait());
    mia::_Events().RegisterObserver(this);
}
void UpSpike::DeActivate()
{
    mia::_Renderer().UnregisterPortrait(&portrait());
    mia::_Events().RemoveObserver(this);
}