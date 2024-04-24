#include "audio.hpp"

namespace mia
{
    AudioManager::AudioManager() = default;
    AudioManager::~AudioManager() = default;

    int AudioManager::Insert(const char *dir, int index)
    {
        Mix_Chunk *mix = Mix_LoadWAV(dir);

        if (mix == NULL)
        {
            // TODO error
            return -1;
        }

        if (index < 0)
        {
            for (int i = 0; i < 65536; i++)
            {
                if (!_mixMap.count(i))
                {
                    index = i;
                    break;
                }
            }
        }

        if (_mixMap.count(index) == 0)
        {
            _mixMap[index] = std::vector<Mix_Chunk*>();
        }
        _mixMap[index].push_back(mix);

        return index;
    }

    bool AudioManager::Play(int index, int loop)
    {
        for (Mix_Chunk *mix : _mixMap[index])
        {
            Mix_PlayChannel(-1, mix, loop);
        }

        return true;
    }
}