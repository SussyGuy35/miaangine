#include "tilemap-data.hpp"

namespace mia
{
    #pragma region Layout
    TilemapLayout::TilemapLayout():
        _width(0),
        _height(0),
        _data(new int[0]),
        _tileDirs(std::vector<std::string>())
    {}

    TilemapLayout::~TilemapLayout()
    {
        delete _data;
        
        _tileDirs.clear();
    }

    int TilemapLayout::getWidth() const
    { 
        return _width; 
    }
    int TilemapLayout::getHeight() const 
    { 
        return _height; 
    }
    int TilemapLayout::getData(int x, int y) const 
    { 
        return _data[x * _width + y]; 
    }
    const char* TilemapLayout::getDir(int index) const
    {
        return _tileDirs[index].c_str();
    }
    #pragma endregion

    #pragma region Palette
    #pragma endregion
}