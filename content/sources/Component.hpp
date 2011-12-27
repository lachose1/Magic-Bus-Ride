#ifndef COMPONENT_H
#define COMPONENT_H

class Game;

class Component
{
public :
    
    virtual void update() = 0;
    Component(Game* game);
    Component();
    ~Component();

protected :
    
    //Game* _game; //Pointeur sur un objet Game
};

#endif