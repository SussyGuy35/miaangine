#pragma once

#include "miaangine.hpp"

class Particle : public mia::Object, public mia::Observer
{
public:
    Particle(const char *source, mia::v2i position, mia::v2i size, mia::v2i sizePerCut);
    ~Particle();

private:
    mia::Clip *_clip;
    bool _playing;

public:
    void Play(mia::v2f position);
    void End();

    void Update(int message) override;
};