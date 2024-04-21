#include "tilemap.hpp"

#include <fstream>
#include <string>

namespace mia
{
    Tilemap::Tilemap(const char *dir, TilemapPalette *palette, v2f size, v2f position):
        _layout(nullptr),
        _palette(palette),
        _width(0),
        _height(0),
        _position(position),
        _size(size)
    {
        LoadLayout(dir);
    }

    Tilemap::~Tilemap()
    {
        delete _layout;
    }

    int Tilemap::width() const
    {
        return _width;
    }
    int Tilemap::height() const
    {
        return _height;
    }
    const TilemapPalette& Tilemap::palette() const
    {
        return *_palette;
    }
    const v2f& Tilemap::position() const
    {
        return _position;
    }
    const v2f& Tilemap::size() const
    {
        return _size;
    }

    int* Tilemap::layout()
    {
        return _layout;
    }
    TilemapPalette& Tilemap::palette()
    {
        return *_palette;
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

    bool Tilemap::LoadLayout(const char *dir)
    {
        std::ifstream input;
        input.open(dir);

        if (!input.is_open()) 
        {
            // TODO error
            throw;
        }

        input >> _width >> _height;
        delete[] _layout;
        _layout = new int[_width * _height];
        for (int j = _height - 1; j >= 0; j--)
        {
            for (int i = 0; i < _width; i++)
            {
                input >> _layout[i + j * _width];
            }
        }

        UpdateLayout();
    }
    void Tilemap::UpdateLayout()
    {
        for (int i = 0; i < _width; i++) 
        {
            for (int j = 0; j < _height; j++)
            {
                if (!HasTile(i, j)) continue;
                if (CheckExposed(i, j))
                {
                    _exposedRects.push_back(GetRect(i, j));
                }
            }
        }
    }

    void Tilemap::SetPalette(TilemapPalette *palette)
    {
        if (!palette)
        {
            // TODO error
        }

        _palette = palette;
    }

    bool Tilemap::HasTile(int x, int y)
    {
        if (x < 0 || x >= _width || y < 0 || y >= _height)
        {
            //TODO error
            return false;
        }

        return (_layout[x + y * _width] > 0);
    }
    Sprite& Tilemap::GetSprite(int x, int y)
    {
        if (x < 0 || x >= _width || y < 0 || y >= _height)
        {
            //TODO error
        }

        return _palette->GetSprite(_layout[x + y * _width]);
    }
    rect Tilemap::GetSpriteRect(int x, int y)
    {
        if (x < 0 || x >= _width || y < 0 || y >= _height)
        {
            //TODO error
        }

        rect res;
        res.siz.x = 1.0 * GetSprite(x, y).siz.x / PPU;
        res.siz.y = 1.0 * GetSprite(x, y).siz.y / PPU;
        res.pos = _position + v2f(x * _size.x, y * _size.y);
        return res;
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
    std::vector<rect>& Tilemap::GetAllExposedRects()
    {
        return _exposedRects;
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

            if (!HasTile(u, v)) return true;
        }

        return false;
    }
}