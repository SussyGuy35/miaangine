#ifndef _MIA_EVENT_LISTENER_INTERFACE_HPP
#define _MIA_EVENT_LISTENER_INTERFACE_HPP

namespace mia 
{
    class IEventListener
    {
    public:
        virtual ~IEventListener() = 0;
 
        virtual void Update(unsigned char message) = 0;
    };
}

#endif