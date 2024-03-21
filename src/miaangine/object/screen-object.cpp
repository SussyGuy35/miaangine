#include "screen-object.hpp"

#include "core/engine-components.hpp"

#include "graphic/image.hpp"

namespace mia
{
    ScreenObject::ScreenObject(const char* name, Vector2 position):
        GameObject(name),
        _position(position)
    {}
    ScreenObject::ScreenObject(const char* name, float x, float y):
        GameObject(name),
        _position(Vector2(x, y))
    {}

    ScreenObject::~ScreenObject()
    {
        for (auto& image : _images) delete(image);
        _images.clear();
    }

    Vector2& ScreenObject::position()
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

    const Vector2& ScreenObject::position() const
    {
        return _position;
    }
    const Image& ScreenObject::image(int index) const
    {
        if (_images.empty() || index >= _images.size()) 
        {
            mia::DebugManager::Instance().Warning("[ScreenObject(%s)] Access denied: [image(%d)] Null reference; Return Null. ", name.str(), index, index);
        }

        return *_images[index];
    }

    Image& ScreenObject::AttachImage(Image* image)
    {
        image->ShiftMaster(this);
        _images.push_back(image);

        return *image;
    }

    Image& ScreenObject::MakeImage(const char* dir, Vector2 size, Vector2 offset)
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