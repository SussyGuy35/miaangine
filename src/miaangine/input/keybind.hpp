#ifndef _MIA_KEYBIND_HPP
#define _MIA_KEYBIND_HPP

#include <string.h>
#include <utility>
#include <list>
#include <map>
#include <stdint.h>

namespace mia
{
    class KeyBind
    {
    public:
        KeyBind();

    private:
        struct cmp_str
        {
            bool operator()(char const *a, char const *b) const
            {
                return strcmp(a, b) < 0;
            }
        };
        std::list<std::pair<const char*, std::pair<uint16_t, uint16_t>>> _keyBind;
        std::map<const char*, uint32_t, cmp_str> _buttonMap;

    public:
        uint16_t GetMainKeyBind(const char *name);
        uint16_t GetAltKeyBind(const char *name);

        void PopulateKeyMap();
    };
}

#endif