#include "tilemap-data.hpp"

namespace mia
{
    #pragma region Layout
    TilemapLayout::TilemapLayout():
        _width(0),
        _height(0),
        _data(new int[0])
    {}
    TilemapLayout::TilemapLayout(const char* layoutDir)
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

    TilemapLayout::~TilemapLayout()
    {
        delete _data;
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
    TilemapPalette::TilemapPalette():
        _tileDirs(std::vector<std::string>())
    {}
    TilemapPalette::TilemapPalette(const char* layoutDir)
    {
        std::ifstream input;
        input.open(dataDir);

        if (!input.is_open()) throw;

        std::string temp;
        while (getline(input, temp))
        {
            _tileDirs.push_back(temp);
        }
    }

    TilemapPalette::~TilemapPalette()
    {
        _tileDirs.clear();
    }

    const char* TilemapPalette::getDir(int index) const
    {
        return _tileDirs[index].c_str();
    }
    #pragma endregion
}