#pragma once

#include "miaangine.hpp"
#include "pipe.hpp"

class PipeManager : public mia::IEventListener
{
public:
    PipeManager();

    void Update(uint8_t message) override;

private:
    Pipe *_pipes[2];
    int _dominantPipe;
    
    void ResetPipe(int index);

public:
    void Start();
    void Stop();
};