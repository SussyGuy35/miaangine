#ifndef _MIA_COMMON_HPP
#define _MIA_COMMON_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <chrono>
#include <random>
#include <cmath>
#include <memory>
#include <algorithm>

#define SDL_MAIN_HANDLED
#include "util/util.hpp"

namespace mia
{
    const int INIT_WINDOW_WIDTH = 1470;
    const int INIT_WINDOW_HEIGHT = 630;

    const float INIT_CAMERA_SIZE = 20; 

    const int PPU = 16;
}

#endif