#include "player-ui.hpp"

#include "player.hpp"
#include "player-movement.hpp"

PlayerUI::PlayerUI(Player *manager):
    _manager(*manager),
    _mainUI(UIMain()),
    _meter(new mia::UI(1, 1)),
    _metterImg(new mia::Image(_meter, nullptr)),
    _maxMeterHeight(170),
    _maxMeterValue(30)
{
    mia::_SpriteHandler().SetSource("./../asset/blank.png");
    _metterImg->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {10, 10}));
    _metterImg->pivot() = {1, 1};
    _metterImg->offset() = {-35, -35};
    _metterImg->size() = mia::v2f(25, _maxMeterHeight);
}

PlayerUI::~PlayerUI()
{}

void PlayerUI::Activate()
{
    mia::_Renderer().RegisterImage(_metterImg);
    _mainUI.Activate();
}
void PlayerUI::DeActivate()
{
    mia::_Renderer().UnregisterImage(_metterImg);
    _mainUI.DeActivate();
}

void PlayerUI::Update()
{
    float speedValue = _manager.movement().GetStoreSpeed();

    _metterImg->size().y = _maxMeterHeight * std::min(1.0, 1.0 * speedValue / _maxMeterValue);
}