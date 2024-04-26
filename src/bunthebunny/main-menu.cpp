#include "main-menu.hpp"

#include "game-manager.hpp"

MainMenu::MainMenu():
    UI(0, 0),
    _image(new mia::Image(this, nullptr)),
    rect00(mia::rect({164.92, 130.2}, {260.4, 195.3})),
    rect01(mia::rect({601.38, 130.2}, {260.4, 195.3})),
    rect02(mia::rect({1024.92, 130.2}, {260.4, 195.3}))
{
    mia::_SpriteHandler().SetSource("./../asset/menu.png");
    _image->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {630, 270}));
    _image->size() = mia::v2f(mia::_Camera().getScreenWidth(), mia::_Camera().getScreenHeight());
}

MainMenu::~MainMenu()
{}

void MainMenu::Activate()
{
    mia::_Renderer().RegisterImage(_image);
    mia::_Events().RegisterObserver(this);
}
void MainMenu::DeActivate()
{
    mia::_Renderer().UnregisterImage(_image);
    mia::_Events().RemoveObserver(this);
}

void MainMenu::Update(int message)
{
    if (message == mia::_EVENT_PRIMARY_UPDATE)
    {
        if (mia::_Input().getMouseButtonDown())
        {
            mia::v2f mousePos = mia::_Input().getMousePosition();

            if (rect00.contain(mousePos))
            {
                GameManager::Instance().LoadLevel(0);
            }
            if (rect01.contain(mousePos))
            {

            }
            if (rect02.contain(mousePos))
            {

            }
        }
    }
}