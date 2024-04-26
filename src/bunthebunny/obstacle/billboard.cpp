#include "billboard.hpp"

const float HEIGHT = 1;
const float WIDTH = 1;

Billboard::Billboard(const char *dir, mia::v2i pos, mia::v2i siz , mia::v2f position):
    Obstacle(position),
    _portrait(new mia::Portrait(this, nullptr))
{
    this->position() = position;

    mia::_SpriteHandler().SetSource(dir);
    _portrait->setSprite(mia::_SpriteHandler().MakeCut(pos, siz));
}

Billboard::~Billboard() = default;

mia::rect Billboard::GetRect() const 
{
    mia::rect res;
    res.pos = position();
    res.siz.x = WIDTH;
    res.siz.y = HEIGHT;
    return res;
}

void Billboard::Update(int massage)
{

}

void Billboard::Activate()
{
    mia::_Renderer().RegisterPortrait(&portrait());
    mia::_Events().RegisterObserver(this);
}
void Billboard::DeActivate()
{
    mia::_Renderer().UnregisterPortrait(&portrait());
    mia::_Events().RemoveObserver(this);
}