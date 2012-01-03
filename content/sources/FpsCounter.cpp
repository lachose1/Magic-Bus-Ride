#include "FpsCounter.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const float FpsCounter::INTERVAL = 1.0f;

FpsCounter::FpsCounter(Game* game) : Component(game)
{
    _fps = -1; //Impossible value as default, so the first computed value is always different.
    _elapsedTime = 0;
    _frames = 0;
    _clock = Clock();

    _clock.Reset();
}

FpsCounter::~FpsCounter()
{
}

void FpsCounter::update()
{
    ++_frames;
    _elapsedTime += _clock.GetElapsedTime();

    if(_elapsedTime > INTERVAL)
    {
        _fps = _frames / _elapsedTime;
        _frames = 0;
        _elapsedTime -= INTERVAL;
        _clock.Reset();
    }
}

float FpsCounter::getFps()
{
    return _fps;
}
