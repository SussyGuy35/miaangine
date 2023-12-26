#ifndef _MIA_KEYBIND_HPP
#define _MIA_KEYBIND_HPP

#include <string>
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
        std::list<std::pair<std::string, std::pair<uint16_t, uint16_t>>> m_keyBind;
        std::map<std::string, uint32_t> m_buttonMap;

    public:
        uint16_t GetMainKeyBind(std::string _name);
        uint16_t GetAltKeyBind(std::string _name);

        void PopulateKeyMap();
    };
}

#endif