#include "player-ui.hpp"

#include "player.hpp"
#include "player-movement.hpp"

#include "game-manager.hpp"

PlayerUI::PlayerUI(Player *manager):
    _manager(*manager),
    _mainUI(UIMain()),
    _meter(new mia::UI(1, 1)),
    _metterImg(new mia::Image(_meter, nullptr)),
    _timer(new mia::UI({0, 0}, {70, 10})),
    _reloadrect(mia::rect({1354.3, 14.01}, {42.03, 42.03})),
    _exitrect(mia::rect({1410.34, 14.01}, {42.03, 42.03})),
    _maxMeterHeight(170),
    _maxMeterValue(30)
{
    mia::_SpriteHandler().SetSource("./../asset/blank.png");
    _metterImg->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {10, 10}));
    _metterImg->pivot() = {1, 1};
    _metterImg->offset() = {-35, -35};
    _metterImg->size() = mia::v2f(25, _maxMeterHeight);
    _timer->SetText(new mia::Text(_timer, "59:59:59"));
}

PlayerUI::~PlayerUI()
{}

void PlayerUI::Activate()
{
    mia::_Renderer().RegisterImage(_metterImg);
    mia::_Renderer().RegisterText(&_timer->text());
    _mainUI.Activate();
}
void PlayerUI::DeActivate()
{
    mia::_Renderer().UnregisterImage(_metterImg);
    mia::_Renderer().UnregisterText(&_timer->text());
    _mainUI.DeActivate();
}

void PlayerUI::Update()
{
    float speedValue = _manager.movement().GetStoreSpeed();

    _metterImg->size().y = _maxMeterHeight * std::min(1.0, 1.0 * speedValue / _maxMeterValue);

    _timer->text().content() = GameManager::Instance().SecondsToTimer(GameManager::Instance().timer).c_str();

    if (mia::_Input().getMouseButtonDown())
        {
            mia::v2f mousePos = mia::_Input().getMousePosition();

            if (_reloadrect.contain(mousePos))
            {
                GameManager::Instance().ReloadLevel();
            }
            if (_exitrect.contain(mousePos))
            {
                GameManager::Instance().LoadMainMenu();
            }
        }
}