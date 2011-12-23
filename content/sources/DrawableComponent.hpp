#ifndef DRAWABLE_COMPONENT_H
#define DRAWABLE_COMPONENT_H

#include "Component.hpp"

class Component;
class Game;

class DrawableComponent : public Component
{
public :

    virtual void draw() = 0;

protected :
    
    DrawableComponent(Game* game);
    ~DrawableComponent();
};

#endif