#ifndef BUS_H
#define BUS_H

#include <SFML/Graphics.hpp>
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

    static const float ACCELERATION;
    static const int MAX_SPEED = 50;
    static const int SPEED_X = 400;
    static const int LANE_WIDTH = 160; //800px / 5 lanes
    static const int JUMP_SPEED = 4;
    static const float JUMP_ACCEL;
    static const int LOWER_BOUND = 600;

    float _speed;
    int _score;
    int _jumpElapsed;
    bool _jumping;
    Lane _lane;
    sf::RenderWindow* _app;
    InputManager* _inputManager;
    std::vector<Animation*> _animations;

    void jump();
    bool isInBounds(float x);
    void setLane();
    void setSubRect();
};

#endif
