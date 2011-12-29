#ifndef BUS_H
#define BUS_H

#include "SpriteComponent.hpp"
#include "Animation.hpp"

class Bus : public SpriteComponent
{
public :

    Bus(Game* game);
    ~Bus();
    void update();
    static const std::string IMAGE_NAME;

private :

    //Animation _animation;
};

#endif