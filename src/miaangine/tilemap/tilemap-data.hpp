#ifndef _MIA_TILEMAP_DATA_HPP
#define _MIA_TILEMAP_DATA_HPP

#include "tilemap-manager.hpp"

#include <vector>
#include <fstream> 

namespace mia
{
    class TilemapData
    {
        friend class TilemapManager;
    
    public:
        TilemapData():
            _width(0),
            _height(0),
            _data(new int[0]),
            _tileDirs(std::vector<const char*>())
        {}

        TilemapData(const char* dataDir)
        {
            std::ifstream input;
            input.open(dataDir);

            if (!input.is_open()) throw;

            input >> _width >> _height;
            _data = new int[_width * _height];
            for (int i = 0; i < _height; i++)
            {
                for (int j = 0; j < _width; j++)
                {
                    input >> _data[(_height - i - 1) * _width + j];
                }
            }
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
            return _tileDirs[index];
        }
    };
}


#endif