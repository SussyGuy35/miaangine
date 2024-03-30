#ifndef _MIA_OBSERVER_HPP
#define _MIA_OBSERVER_HPP

namespace mia
{
    class Observer
    {
    public:
        Observer();
        virtual ~Observer();

        virtual void Update(int message) = 0;
    };
}

#endif