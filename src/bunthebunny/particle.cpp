#include "particle.hpp"

float _timePerFrame = 0.1; 
float _frameTimer = _timePerFrame;

Particle::Particle(const char *source, mia::v2i position, mia::v2i size, mia::v2i sizePerCut):
    Object("Particle"),
    _clip(new mia::Clip()),
    _playing(false)
{
    _clip->MakeAnimation(source, position, size, sizePerCut);
    mia::Portrait *portrait = new mia::Portrait(this, nullptr, {.5, .5});

    mia::_Events().RegisterObserver(this);
}

Particle::~Particle()
{
    delete _clip;
}

void Particle::Play(mia::v2f position)
{
    if (_playing) End();

    mia::_Renderer().RegisterPortrait(&portrait());
    portrait().setSprite(_clip->GetCurrentSprite());
    this->position() = position;
    _frameTimer = _timePerFrame;

    _playing = true;
}

void Particle::End()
{
    mia::_Renderer().UnregisterPortrait(&portrait());
    _clip->SetIndex(0);

    _playing = false;
}

void Particle::Update(int message)
{
    if (message == mia::_EVENT_PRIMARY_UPDATE)
    {
        if (_playing)
        {
            _frameTimer -= mia::_Time().deltaTime();
            if (_frameTimer <= 0)
            {
                portrait().setSprite(_clip->NextSprite());
                if (_clip->IsLastFrame()) 
                {
                    End();
                }

                _frameTimer = _timePerFrame;
            }
        }
    }
}