#include "renderer.hpp"

namespace mia
{
    Renderer *Renderer::__instance = nullptr;

    Renderer::Renderer()
    {}

    Renderer::~Renderer()
    {
        __instance = nullptr;
    }
}