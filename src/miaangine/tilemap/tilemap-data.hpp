#ifndef _MIA_TILEMAP_DATA_HPP
#define _MIA_TILEMAP_DATA_HPP

#include "tilemap-manager.hpp"

#include <vector>

namespace mia
{
    class TilemapData
    {
        friend class TilemapManager;
    
    public:
        TilemapData(const char* dataDir = ""):
        {
            // TODO Read input from .txt
        }

        ~TilemapData()
        {
            delete _data;
            for (const char* t : _tileDirs) delete t;
            _tileDirs.clear();
        }

    private:
        // Attributes
        int _width, _height;
        int *_data;
        std::vector<const char*> _tileDirs;

    public:
        // Attributes accessing
        int getWidth() const 
        { 
            return _width; 
        }
        int getHeight() const 
        { 
            return _height; 
        }
        int getData(int x, int y) const 
        { 
            return _data[x * _width + y]; 
        }
        const char* getDir(int index) const
        {
            return tileDirs[index];
        }
    };
}


#endif