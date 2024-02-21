#ifndef _MIA_EVENT_LISTENER_INTERFACE_HPP
#define _MIA_EVENT_LISTENER_INTERFACE_HPP

namespace mia 
{
    class IEventListener
    {
    public:
        virtual void Update(uint8_t message) = 0;
    };
}

#endif