#include "tilemap.hpp"

namespace mia
{
    Tilemap::Tilemap():
        _data(nullptr),
        _palette(nullptr),
        _width(0),
        _height(0),
        _position(v2f::zero()),
        _size(v2f::zero())
    {}

    Tilemap::~Tilemap()
    {
        delete _data;
    }

    int Tilemap::width() const
    {
        return _width;
    }
    int Tilemap::height() const
    {
        return _height;
    }
    const v2f& Tilemap::position() const
    {
        return _position;
    }
    const v2f& Tilemap::size() const
    {
        return _size;
    }

    int* Tilemap::data()
    {
        return _data;
    }
    TilemapPalette* Tilemap::palette()
    {
        return _palette;
    }
    int& Tilemap::width()
    {
        return _width;
    }
    int& Tilemap::height()
    {
        return _height;
    }
    v2f& Tilemap::position()
    {
        return _position;
    }
    v2f& Tilemap::size()
    {
        return _size;
    }

    Sprite* Tilemap::GetSprite(int x, int y)
    {
        if (x < 0 || x >= _width || y < 0 || y >= _height)
        {
            //TODO error
        }

        return _palette->GetSprite(_data[x * _width + y]);
    }
    rect Tilemap::GetRect(int x, int y)
    {
        if (x < 0 || x >= _width || y < 0 || y >= _height)
        {
            //TODO error
        }

        rect res;
        res.siz = _size;
        res.pos = _position + v2f(x * _size.x, y * _size.y);
        return res;
    }
    std::vector<rect> Tilemap::GetAllExposedRects()
    {
        std::vector<rect> res;
        for (int i = 0; i < _width; i++) 
        {
            for (int j = 0; j < _height; j++)
            {
                if (CheckExposed(i, j))
                {
                    res.push_back(GetRect(i, j));
                }
            }
        }

        return res;
    }

    bool Tilemap::CheckExposed(int x, int y)
    {
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };
        for (int i = 0; i < 4; i++)
        {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u < 0 || u > _width || v < 0 || v > _height) continue;

            if (_data[u * _width + v] <= 0) return true;
        }

        return false;
    }
}