#ifndef _MIA_EVENT_LISTENER_INTERFACE_HPP
#define _MIA_EVENT_LISTENER_INTERFACE_HPP

namespace mia 
{
    class IEventListener
    {
    public:
        virtual void Update() = 0;
    };
}

#endif