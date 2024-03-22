#ifndef _MIA_EVENT_LISTENER_INTERFACE_HPP
#define _MIA_EVENT_LISTENER_INTERFACE_HPP

namespace mia 
{
    class IEventListener
    {
    public:
        virtual ~IEventListener() {}
 
        virtual void Update(unsigned char message) = 0;
    };
}

#endif