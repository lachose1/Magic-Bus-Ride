#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include <SFML/Graphics.hpp>

#include "Component.hpp"

class Game;

class FpsCounter : public Component
{
public:
    FpsCounter(Game* game);
    ~FpsCounter();
    void update();
    float getFps();

private:
    static const float INTERVAL;

    Game* _game;
    float _fps;
    float _elapsedTime;
    sf::RenderWindow* _app;

};

#endif
