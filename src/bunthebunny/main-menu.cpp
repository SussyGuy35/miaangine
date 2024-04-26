#include "main-menu.hpp"

#include "game-manager.hpp"

MainMenu::MainMenu():
    UI(0, 0),
    _image(new mia::Image(this, nullptr)),
    rect00(mia::rect({164.92, 130.2}, {260.4, 195.3})),
    rect01(mia::rect({601.38, 130.2}, {260.4, 195.3})),
    rect02(mia::rect({1024.92, 130.2}, {260.4, 195.3})),
    text00(new mia::UI({0, 0}, {164.92  + 10, 130.2 + 195.3 + 40})),
    text01(new mia::UI({0, 0}, {601.38  + 10, 130.2 + 195.3 + 40})),
    text02(new mia::UI({0, 0}, {1024.92 + 10, 130.2 + 195.3 + 40}))
{
    mia::_SpriteHandler().SetSource("./../asset/menu.png");
    _image->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {630, 270}));
    _image->size() = mia::v2f(mia::_Camera().getScreenWidth(), mia::_Camera().getScreenHeight());

    text00->SetText(new mia::Text(text00, "59:59:59"));
    text01->SetText(new mia::Text(text01, "59:59:59"));
    text02->SetText(new mia::Text(text02, "59:59:59"));
}

MainMenu::~MainMenu()
{}

void MainMenu::Activate()
{
    mia::_Renderer().RegisterImage(_image);
    mia::_Events().RegisterObserver(this);

    mia::_Renderer().RegisterText(&text00->text());
    mia::_Renderer().RegisterText(&text01->text());
    mia::_Renderer().RegisterText(&text02->text());
}
void MainMenu::DeActivate()
{
    mia::_Renderer().UnregisterImage(_image);
    mia::_Events().RemoveObserver(this);

    mia::_Renderer().UnregisterText(&text00->text());
    mia::_Renderer().UnregisterText(&text01->text());
    mia::_Renderer().UnregisterText(&text02->text());
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