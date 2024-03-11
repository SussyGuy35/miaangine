#include "screen-object.hpp"

#include "graphic/image.hpp"

namespace mia
{
    ScreenObject::ScreenObject(const char* name, Vector2 position):
        GameObject(name),
        position(position)
    {}
    ScreenObject::ScreenObject(const char* name, float x, float y):
        GameObject(name),
        position(Vector2(x, y))
    {}

    ScreenObject::~ScreenObject()
    {
        for (auto& image : _images) delete(image);
        _images.clear();
    }

    Image *ScreenObject::image(int index)
    {
        if (_images.empty()) 
        {
            SDL_LogMessage(SDL_LOG_CATEGORY_ERROR, SDL_LOG_PRIORITY_INFO, "ScreenObject > Image: Null reference"); //FIXME
            return nullptr;
        }

        return _images[index];
    }

    void ScreenObject::AttachImage(Image *image)
    {
        image->ShiftMaster(this);
        _images.push_back(image);
    }

    void ScreenObject::MakeImage(Vector2 size, Vector2 offset)
    {
        Image *image = new Image(size, offset);

        image->ShiftMaster(this);
        _images.push_back(image);
    }
    void ScreenObject::MakeImage(float sx, float sy, float ox, float oy)
    {
        Image *image = new Image(sx, sy, ox, oy);

        image->ShiftMaster(this);
        _images.push_back(image);
    }
}