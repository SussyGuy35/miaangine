#include "ui-main.hpp"

UIMain::UIMain():
    UI(0, 0),
    _image(new mia::Image(this, nullptr))
{
    mia::_SpriteHandler().SetSource("D:/SDL/miaangine/asset/UI.png");
    _image->setSprite(mia::_SpriteHandler().MakeCut({0, 0}, {240, 135}));
    _image->size() = mia::v2f(mia::_Camera().getScreenWidth(), mia::_Camera().getScreenHeight());
    mia::_Renderer().RegisterImage(_image);
}

UIMain::~UIMain()
{
    
}
