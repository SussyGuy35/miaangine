#include "main-menu.hpp"

#include "game-manager.hpp"

#include <iomanip>
#include <sstream>
#include <string>

MainMenu::MainMenu():
    UI(0, 0),
    _image(new mia::Image(this, nullptr)),
    rect00(mia::rect({164.92, 130.2}, {260.4, 195.3})),
    rect01(mia::rect({601.38, 130.2}, {260.4, 195.3})),
    rect02(mia::rect({1024.92, 130.2}, {260.4, 195.3})),
    text00(new mia::UI({0, 0}, {164.92  + 35, 130.2 + 195.3 + 40})),
    text01(new mia::UI({0, 0}, {601.38  + 35, 130.2 + 195.3 + 40})),
    text02(new mia::UI({0, 0}, {1024.92 + 35, 130.2 + 195.3 + 40}))
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

    text00->text().content() = SecondsToTimer(GameManager::Instance().GetScore(0)).c_str();
    text01->text().content() = SecondsToTimer(GameManager::Instance().GetScore(1)).c_str();
    text02->text().content() = SecondsToTimer(GameManager::Instance().GetScore(2)).c_str();

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
                GameManager::Instance().LoadLevel(1);
            }
            if (rect02.contain(mousePos))
            {
                GameManager::Instance().LoadLevel(2);
            }
        }
        else 
        {
            if (mia::_Input().getKeyDown(SDL_SCANCODE_1))
            {
                GameManager::Instance().LoadLevel(0);
            }
            if (mia::_Input().getKeyDown(SDL_SCANCODE_2))
            {
                GameManager::Instance().LoadLevel(1);
            }
            if (mia::_Input().getKeyDown(SDL_SCANCODE_3))
            {
                GameManager::Instance().LoadLevel(2);
            }
        }
        
    }
}

std::string MainMenu::SecondsToTimer(float value) 
{
    int minutes = static_cast<int>(value / 60);
    value -= minutes * 60;
    int seconds = static_cast<int>(value);
    value -= seconds;
    int ticks = static_cast<int>(value * 100); 

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setw(2) << seconds << ":"
        << std::setw(2) << ticks;

    return ss.str();
}