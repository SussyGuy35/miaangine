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
        ScreenObject(const char* name = "object", vector2 position = vector2::zero());
        ScreenObject(const char* name, float x, float y);

        virtual ~ScreenObject();

    private:
        vector2 _position;
        
        std::vector<Image*> _images;

    public:
        vector2& position();

        Image& image(int index = 0);

        Image& AttachImage(Image *portrait);

        Image& MakeImage(const char* dir = "", vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Image& MakeImage(const char* dir, float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif