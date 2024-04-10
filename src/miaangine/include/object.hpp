#ifndef _MIA_OBJECT_HPP
#define _MIA_OBJECT_HPP

#include "common.hpp"

#include "entity.hpp"

namespace mia
{
    class Portrait;
    class Body;

    class Object : public Entity
    {
    public:
        Object(const char *name = "Untitled", v2f position = v2f::zero());
        Object(const char *name, float x, float y);
        Object(float x, float y);
        virtual ~Object();

    private:
        string _name;
        uint32_t _tag;

        v2f _position;

        Portrait *_portrait;
        Body *_body;

    public:
        string name() const;
        uint32_t getTag() const;
        const v2f& position() const;
        const Portrait& portrait() const;
        const Body& body() const;

        string& name();
        v2f& position();
        Portrait& portrait();
        Body& body();
        
        bool IsContainTag(int tag);
        uint32_t AddTag(int tag);
        uint32_t RemoveTag(int tag);

        // Portrait& MakePortrait();
        // Body& MakeBody();

    public:
        int getID() const override;
        const char* ToStr() const override;
    };
}

#endif