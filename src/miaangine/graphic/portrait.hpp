#ifndef _MIA_PORTRAIT_HPP
#define _MIA_PORTRAIT_HPP

#include <SDL.h>
#include <memory>

#include "util/math.hpp"
#include "util/string.hpp"

#include "object/world-object.hpp"

// namespace mia 
// {
    class mia::Portrait
    {
    public:
        Portrait(const char* dir = "", float scale = 1, vector2 offset = vector2::zero());

        virtual ~Portrait();

    private:
        string _ucName;
        vector2 _ucPosition;

        WorldObject *_master;

    public:
        string file;
        float scale;
        vector2 offset;

        string& name() ;
        vector2& position() ;

        WorldObject* master();

        SDL_Color color;

        void ShiftMaster(WorldObject *master);
    };
// }

#endif