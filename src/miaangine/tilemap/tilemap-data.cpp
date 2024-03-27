#include "tilemap-data.hpp"

#include "core/engine-components.hpp"

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
        input.open(layoutDir);

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

    int TilemapLayout::width() const
    { 
        return _width; 
    }
    int TilemapLayout::height() const 
    { 
        return _height; 
    }
    int TilemapLayout::getData(int x, int y) const 
    { 
        return _data[x * _width + y]; 
    }

    int TilemapLayout::width(int value)
    {
        _width = value;
    }
    int TilemapLayout::height(int value)
    {
        _height = value;
    }
    int TilemapLayout::setData(int x, int y, int value)
    {
        _data[x * _width + y] = value;
    }
    #pragma endregion

    #pragma region Palette
    TilemapPalette::TilemapPalette()
    {}
    TilemapPalette::TilemapPalette(const char* layoutDir)
    {
        std::ifstream input;
        input.open(layoutDir);

        if (!input.is_open()) throw;

        std::string temp;
        while (getline(input, temp))
        {
            _tileDirs.push_back(temp);
            _tileTextures.push_back(IMG_LoadTexture(generic().renderer, _tileDirs.back().c_str()));
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

    SDL_Texture* TilemapPalette::texture(int index)
    {
        return _tileTextures[index];
    }
    #pragma endregion
}