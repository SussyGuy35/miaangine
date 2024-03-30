#ifndef _MIA_INPUT_HPP
#define _MIA_INPUT_HPP

#include "common.hpp"

namespace mia
{
    class Input : public Singleton<Input>
    {
    #pragma region Constructor Destructor
        friend class Singleton<Input>;
        Input();
        ~Input();
    #pragma endregion

    #pragma region Attribute
        
    #pragma endregion
    };
}

#endif