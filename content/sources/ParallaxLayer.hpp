#ifndef PARALLAXLAYER_H
#define PARALLAXLAYER_H

#include "SpriteComponent.hpp"

class ParallaxLayer : public SpriteComponent
{
public :

    ParallaxLayer(Game* game, std::string image, int level);
    ~ParallaxLayer();
    void update();

private :

    int _level;
    int _width;
    int _height;
    sf::IntRect _currentRect;
    int _currentX;
    int _currentY;
    int _windowX;
    int _windowY;
};

#endif
