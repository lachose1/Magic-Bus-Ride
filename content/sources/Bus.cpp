#include "Bus.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Bus::IMAGE_NAME = "bus.png";

Bus::Bus(Game* game) : SpriteComponent(game, IMAGE_NAME)
{
}

Bus::~Bus()
{
}

void Bus::update()
{
    return;
}
