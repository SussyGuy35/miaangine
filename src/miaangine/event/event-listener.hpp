#ifndef _MIA_EVENT_LISTENER_HPP
#define _MIA_EVENT_LISTENER_HPP

namespace mia 
{
    class EventListener
    {
    public:
        virtual ~EventListener() {}
 
        virtual void Update(unsigned char message) = 0;
    };
}

#endif