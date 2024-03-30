#include "miaangine.hpp"
#include <string>

int main(int argc, char* argv[])
{
    mia::Game::Instance().InitWindow();

    mia::Object *obj = new mia::Object("no");
    std::cout << obj->name();
    obj->name() = "1280312";
    std::cout << obj->name();

    SDL_Delay(1000);

    return 0;
}