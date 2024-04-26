#include "ui-main.hpp"

UIMain::UIMain():
    UI(0, 0),
    _image(new mia::Image(this, nullptr))
{
    mia::_SpriteHandler().SetSource("./../asset/UI.png");
    _image->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {315, 135}));
    _image->size() = mia::v2f(mia::_Camera().getScreenWidth(), mia::_Camera().getScreenHeight());
}

UIMain::~UIMain()
{
    
}

void UIMain::Activate()
{
    mia::_Renderer().RegisterImage(_image);
}
void UIMain::DeActivate()
{
    mia::_Renderer().UnregisterImage(_image);
}
