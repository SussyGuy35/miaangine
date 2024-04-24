#ifndef _MIA_AUDIO_HPP
#define _MIA_AUDIO_HPP

#include "common.hpp"

namespace mia
{
    class AudioManager : public Singleton<AudioManager>
    {
    private:
        friend class Singleton<AudioManager>;
        AudioManager();
        ~AudioManager();

    private:
        std::map<int, std::vector<Mix_Chunk*>> _mixMap; 

    public:
        int Insert(const char *dir, int index = -1);

        bool Play(int index, int loop = 0);
    };
}

#endif