#include "startmenu.hpp"

#include "game-manager.hpp"

StartM::StartM():
    _image(new mia::Image(this, nullptr))
{
    mia::_SpriteHandler().SetSource("./../asset/outmenu.png");
    _image->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {630, 270}));
    _image->size() = mia::v2f(mia::_Camera().getScreenWidth(), mia::_Camera().getScreenHeight());
    mia::_Renderer().RegisterImage(_image);

    mia::_Events().RegisterObserver(this);
}

StartM::~StartM()
{
    delete _image;
    mia::_Events().RemoveObserver(this);
}

void StartM::Update(int message)
{
    if (message == mia::_EVENT_PRIMARY_UPDATE)
    {
        if (mia::_Input().getKeyDown(SDL_SCANCODE_X))
        {
            GameManager::Instance().LoadMainMenu();

            mia::_Renderer().UnregisterImage(_image);
            mia::_Events().RemoveObserver(this);
        }
    }
}