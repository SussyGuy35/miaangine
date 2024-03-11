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

    public:
        Vector2 position;

    protected:
        std::vector<Image*> _portraits;

    public:
        Image *portrait(int index = 0);\

        void AttachImage(Image *portrait);

        void MakeImage(Vector2 size = Vector2::zero(), Vector2 offset = Vector2::zero());
        void MakeImage(float sx, float sy, float ox = 0, float oy = 0);
    };
}

#endif