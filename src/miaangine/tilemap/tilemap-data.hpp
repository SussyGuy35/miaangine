#ifndef _MIA_TILEMAP_DATA_HPP
#define _MIA_TILEMAP_DATA_HPP

#include "tilemap-manager.hpp"

#include <vector>
#include <fstream> 
#include <string>

namespace mia
{
    class TilemapLayout
    {
        friend class TilemapManager;
    
    public:
        TilemapLayout();

        TilemapLayout(const char* dataDir)
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

            std::string temp;
            while (getline(input, temp)) 
            {
                _tileDirs.push_back(temp);
                temp.erase();
            }
        }   

        ~TilemapLayout();

    private:
        // Attributes
        int _width, _height;
        int *_data;
        std::vector<std::string> _tileDirs;

    public:
        // Attributes accessing
        int getWidth() const;
        int getHeight() const;
        int getData(int x, int y) const;
        const char* getDir(int index) const;
    };

    class TilemapPalette
    {

    };
}


#endif