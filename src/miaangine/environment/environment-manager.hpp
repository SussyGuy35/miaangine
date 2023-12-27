#ifndef _MIA_OBJECT_MAKER_HPP
#define _MIA_OBJECT_MAKER_HPP

#include "object.hpp"

namespace mia
{
    class Environment
    {
    private:
        Environment() = delete;
        ~Environment();

    public:
        static Object* Make(Object _object);
    };
}

#endif