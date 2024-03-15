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

    public:
        vector2 position;

    protected:
        std::vector<Image*> _images;

    public:
        Image& image(int index = 0);

        Image& AttachImage(Image *portrait);

        Image& MakeImage(vector2 size = vector2::zero(), vector2 offset = vector2::zero());
        Image& MakeImage(float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif