#ifndef _MIA_MASK_HPP
#define _MIA_MASK_HPP

namespace mia
{
    class mask
    {
    public:
        int data;

        inline mask(int data): 
            data(data)
        {}

    public: 
        inline void insert(int pos)
        {
            if (pos > 32) return;
            data |= (1 << pos);
        }

        inline void remove(int pos)
        {
            if (pos > 32) return;
            data &= ~(1 << pos);
        }

        inline bool query(int pos)
        {
            if (pos > 32) return false;
            return ((data >> pos) & 1);
        }

        inline int count()
        {
            return __builtin_popcount(data);
        }

        inline int get()
        {
            return data;
        }
    };
}

#endif