#include "ParallaxLayer.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

ParallaxLayer::ParallaxLayer(Game* game, string image, int level) : SpriteComponent(game, image), _level(level)
{
    _width = _game->getImageManager()->find(image)->GetWidth();
    _height = _game->getImageManager()->find(image)->GetHeight();
    _currentX = _width/2 - 400;
    _currentY = _height - 600;

    _sprite.SetSubRect(IntRect(_currentX, _currentY, _currentX + 800, _currentY + 600));
}

ParallaxLayer::~ParallaxLayer()
{
}

void ParallaxLayer::update()
{
    _currentY = (_height-600)*(_game->getCompletionPercentage()/100);
    _sprite.SetSubRect(IntRect(_currentX, _currentY, _currentX + 800, _currentY + 600));
}