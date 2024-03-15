#include "screen-object.hpp"

#include "graphic/image.hpp"

#include "debug/debug-manager.hpp"

namespace mia
{
    ScreenObject::ScreenObject(const char* name, vector2 position):
        GameObject(name),
        position(position)
    {}
    ScreenObject::ScreenObject(const char* name, float x, float y):
        GameObject(name),
        position(vector2(x, y))
    {}

    ScreenObject::~ScreenObject()
    {
        for (auto& image : _images) delete(image);
        _images.clear();
    }

    Image *ScreenObject::image(int index)
    {
        if (_images.empty() || index >= _images.size()) 
        {
            mia::DebugManager::Instance().Warning("[ScreenObject] access denied: [image(%d)] Null reference", index); //FIXME
            return nullptr;
        }

        return _images[index];
    }

    void ScreenObject::AttachImage(Image *image)
    {
        image->ShiftMaster(this);
        _images.push_back(image);
    }

    void ScreenObject::MakeImage(vector2 size, vector2 offset)
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