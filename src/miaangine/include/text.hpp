#ifndef _MIA_TEXT_HPP
#define _MIA_TEXT_HPP

#include "UI.hpp"

#include "util/rect.hpp"

namespace mia
{
    class Text : public Entity
    {
    public:
        Text(UI *master, const char *content = "", v2f offset = v2f::zero());
        virtual ~Text();

    private:
        UI *_master;

        string _content;
        v2f _offset;

    public:
        const UI& master() const;
        const char* content() const;
        const v2f& offset() const;

        UI& master();
        string& content();
        v2f& offset();

        UI& ChangeMaster(UI *newMaster);
        v2f GetPos() const; 

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif