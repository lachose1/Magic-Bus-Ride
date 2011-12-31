#ifndef BUS_H
#define BUS_H

#include "SpriteComponent.hpp"
#include "Animation.hpp"
#include "InputManager.hpp"

class Bus : public SpriteComponent
{
public :
    enum Lane {LEFT_EDGE, LEFT, CENTER, RIGHT, RIGHT_EDGE};
    static const std::string IMAGE_NAME;

    Bus(Game* game);
    ~Bus();

    void update();
    int getSpeed();
    int getScore();
    bool isAnimated();
    bool isJumping();
    Lane getLane();

private :

    static const int ACCELERATION = 1;
    static const int MAX_SPEED = 300;
    static const int SPEED_X = 5;
    static const int LANE_WIDTH = 160; //800px / 5 lanes
    static const int JUMP_DURATION = 30;
    static const int JUMP_HEIGHT = 150;
    static const int JUMP_SPEED = 10; //2 * height / duration

    int _speed;
    int _score;
    int _jumpElapsed;
    bool _jumping;
    Lane _lane;
    InputManager* _inputManager;
    std::vector<Animation*> _animations;

    void jump();
    bool isInBounds(float x);
    void setLane();
    void setSubRect();
};

#endif
