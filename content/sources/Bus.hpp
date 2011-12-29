#ifndef BUS_H
#define BUS_H

#include <SFML/Graphics.hpp>
#include "SpriteComponent.hpp"
#include "Animation.hpp"

class Bus : public SpriteComponent
{
public :

    Bus(Game* game, sf::Image* image);
    ~Bus();
    void update();
    void draw();

private :

    //Animation _animation;
};

#endif