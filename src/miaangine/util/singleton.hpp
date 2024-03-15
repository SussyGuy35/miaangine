#ifndef _MIA_SINGLETON_HPP
#define _MIA_SINGLETON_HPP

namespace mia
{
    template <typename T> 
    class Singleton
    {
    protected:
        Singleton() {};

    public:
        Singleton(Singleton const &) = delete;
        Singleton& operator=(Singleton const &) = delete;
    
        static T& Instance()
        {
            static T _instance;
            return _instance;
        }
    };
}

#endif