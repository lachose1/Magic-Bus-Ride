#ifndef COMPONENT_H
#define COMPONENT_H

#include "Game.hpp"

class Game;

class Component
{
public :
    
    virtual void update() = 0;

protected :
    
    Component(Game* game);
    ~Component();
    Game* _game; //Pointeur sur un objet Game
};

#endif