#include "screen-object.hpp"

#include "core/engine-components.hpp"

#include "graphic/image.hpp"

namespace mia
{
    ScreenObject::ScreenObject(const char* name, vector2 position):
        GameObject(name),
        _position(position)
    {}
    ScreenObject::ScreenObject(const char* name, float x, float y):
        GameObject(name),
        _position(vector2(x, y))
    {}

    ScreenObject::~ScreenObject()
    {
        for (auto& image : _images) delete(image);
        _images.clear();
    }

    vector2& ScreenObject::position()
    {
        return _position;
    }

    Image& ScreenObject::image(int index)
    {
        if (_images.empty() || index >= _images.size()) 
        {
            mia::DebugManager::Instance().Warning("[ScreenObject(%s)] Access denied: [image(%d)] Null reference; Created new [image(%d)]. ", name.str(), index, index);
            return MakeImage();
        }

        return *_images[index];
    }

    Image& ScreenObject::AttachImage(Image* image)
    {
        image->ShiftMaster(this);
        _images.push_back(image);

        return *image;
    }

    Image& ScreenObject::MakeImage(const char* dir, vector2 size, vector2 offset)
    {
        Image *image = new Image(dir, size, offset);

        image->ShiftMaster(this);
        _images.push_back(image);

        return *image;
    }
    Image& ScreenObject::MakeImage(const char* dir, float sx, float sy, float ox, float oy)
    {
        Image *image = new Image(dir, sx, sy, ox, oy);

        image->ShiftMaster(this);
        _images.push_back(image);

        return *image;
    }
}