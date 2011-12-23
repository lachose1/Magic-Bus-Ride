#include "Game.hpp"
#include "Component.hpp"

using namespace std;

Component::Component(Game* game) : _game(game)
{
}

Component::~Component()
{
    delete _game;
}
