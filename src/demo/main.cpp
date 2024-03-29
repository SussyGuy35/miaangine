#include "miaangine.hpp"

int main(int argc, char* argv[])
{
    mia::string str("123");
    str += "4"; 
    printf(str.str());

    mia::v2f v(10, 10);
    v = 10 * v;
}