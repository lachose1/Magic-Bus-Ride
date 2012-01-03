#include "FpsCounter.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const float FpsCounter::INTERVAL = 1.0f;

FpsCounter::FpsCounter(Game* game) : Component(game)
{
    _fps = -1; //Impossible value as default, so the first computed value is always different.
    _app = game->getApp();
    _elapsedTime = 0;
}

FpsCounter::~FpsCounter()
{
}

void FpsCounter::update()
{
    _elapsedTime += _app->GetFrameTime();

    if(_elapsedTime > INTERVAL)
    {
        _fps = 1.0f / _app->GetFrameTime();
        _elapsedTime -= INTERVAL;
    }
}

float FpsCounter::getFps()
{
    return _fps;
}
