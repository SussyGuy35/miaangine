#ifndef _MIA_TILEMAP_HANDLER_HPP
#define _MIA_TILEMAP_HANDLER_HPP

#include "common.hpp"

namespace mia
{
    class TilemapHandler : public Singleton<TilemapHandler>
    {
    private:
        friend class Singleton<TilemapHandler>;
        TilemapHandler();
        ~TilemapHandler();

    private:
        
    };
}

#endif