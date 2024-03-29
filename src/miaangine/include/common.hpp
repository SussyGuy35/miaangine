#ifndef _MIA_COMMON_HPP
#define _MIA_COMMON_HPP

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <random>
#include <cmath>
#include <memory>

#define SDL_MAIN_HANDLED
#include "util/util.hpp"

namespace mia
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const int PPU = 16;
}

#endif