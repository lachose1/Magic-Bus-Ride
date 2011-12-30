#ifndef BUS_H
#define BUS_H

#include "SpriteComponent.hpp"
#include "Animation.hpp"
#include "InputManager.hpp"

class Bus : public SpriteComponent
{
public :

    Bus(Game* game);
    ~Bus();
    void update();
    static const std::string IMAGE_NAME;
    int getSpeed();
    int getScore();

private :

    static const int ACCELERATION = 1;
    static const int SPEED_X = 10;
    int _speed;
    int _score;
    InputManager* _inputManager;
    //std::vector<Animation*> _animations;

    bool isInBounds(float x);
};

#endif