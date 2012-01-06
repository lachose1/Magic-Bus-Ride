#ifndef BUS_H
#define BUS_H

#include <SFML/Graphics.hpp>
#include "SpriteComponent.hpp"
#include "Animation.hpp"
#include "InputManager.hpp"

class Bus : public SpriteComponent
{
public :
    static const std::string IMAGE_NAME;

    Bus(Game* game);
    ~Bus();

    void update();
    void draw();
    void drawShadow();
    void drawCollisionSquare();
    int getSpeed();
    int getScore();
    bool isMoving();
    bool isJumping();
    bool isAlive();
    int getLane();

private :

    static const float ACCELERATION;
    static const int MAX_SPEED = 50;
    static const int SPEED_X = 400;
    static const int LANE_WIDTH = 90;
    static const int VOID_WIDTH = 85;
    static const int JUMP_SPEED = 4;
    static const float JUMP_ACCEL;
    static const int LOWER_BOUND = 550;
    static const float SHADOW_SIZE;
    static const float BLINK_INTERVAL;
    static const float BLINK_MAX;

    float _speed;
    float _blinkElapsed;
    int _score;
    int _jumpElapsed;
    bool _jumping;
    bool _alive;
    bool _blinking;
    int _lane;
    sf::RenderWindow* _app;
    InputManager* _inputManager;
    std::vector<Animation*> _animations;

    void jump();
    void blink();
    void handleInput(float& x);
    bool isOnHole();
    bool isInBounds(float x);
    void setLane();
    void setSubRect();
    void resetPosition();
};

#endif
