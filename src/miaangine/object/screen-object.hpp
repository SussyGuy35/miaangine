#ifndef _MIA_SCREEN_OBJECT_HPP
#define _MIA_SCREEN_OBJECT_HPP

#include <vector>

#include "game-object.hpp"

#include "util/math.hpp"

namespace mia 
{
    class Image;
    class ScreenObject : public GameObject
    {
    public:
        ScreenObject(const char* name = "object", Vector2 position = Vector2::zero());
        ScreenObject(const char* name, float x, float y);

        virtual ~ScreenObject();

    private:
        Vector2 _position;
        
        std::vector<Image*> _images;

    public:
        Vector2& position();
        Image& image(int index = 0);

        const Vector2& position() const;
        const Image& image(int index = 0) const;

        Image& AttachImage(Image *portrait);

        Image& MakeImage(const char* dir = "", Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        Image& MakeImage(const char* dir, float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif