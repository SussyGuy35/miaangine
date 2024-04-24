#include "player-ui.hpp"

#include "player.hpp"
#include "player-movement.hpp"

PlayerUI::PlayerUI(Player *manager):
    _manager(*manager),
    _meter(new mia::UI(1, 1)),
    _metterImg(new mia::Image(_meter, nullptr)),
    _maxMeterHeight(241),
    _maxMeterValue(30)
{
    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/blank.png");
    _metterImg->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {10, 10}));
    _metterImg->pivot() = {1, 1};
    _metterImg->offset() = {-79, -60};
    _metterImg->size() = mia::v2f(60, _maxMeterHeight);
    mia::_Renderer().RegisterImage(_metterImg);
}

PlayerUI::~PlayerUI()
{}

void PlayerUI::Update()
{
    float speedValue = _manager.movement().GetStoreSpeed();

    _metterImg->size().y = _maxMeterHeight * (speedValue / _maxMeterValue);
}