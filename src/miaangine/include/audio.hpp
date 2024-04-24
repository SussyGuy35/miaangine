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

    
    };
}

#endif