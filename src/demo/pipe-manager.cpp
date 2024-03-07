#include "pipe-manager.hpp"

PipeManager::PipeManager()
{
    _pipes[0] = new Pipe();
    _pipes[1] = new Pipe();

    _dominantPipe = 0;
    
    ResetPipe(0);
    ResetPipe(1);
    _pipes[0]->moving = false;
    _pipes[1]->moving = false;

    mia::events->primaryUpdate->RegisterListener(this);
}

void PipeManager::Update(uint8_t message)
{
    switch (message)
    {
    case mia::_EVENT_PRIMARY_UPDATE:
        if (_pipes[_dominantPipe]->position.x < 100) 
        {
            _dominantPipe = 1 - _dominantPipe;
            ResetPipe(_dominantPipe);
        }
        break;
    
    default:
        break;
    }
}

void PipeManager::ResetPipe(int index)
{
    _pipes[index]->Reset();
    _pipes[index]->moving = true;
}

void PipeManager::Start()
{
    _pipes[_dominantPipe]->moving = true;
}

void PipeManager::Stop()
{
    _pipes[0]->moving = false;
    _pipes[1]->moving = false;
}