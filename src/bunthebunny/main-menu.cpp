#include "main-menu.hpp"

MainMenu::MainMenu():
    UI(0, 0),
    _image(new mia::Image(this, nullptr))
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
}
void MainMenu::DeActivate()
{
    mia::_Renderer().UnregisterImage(_image);
}

void MainMenu::Update(int message)
{

}