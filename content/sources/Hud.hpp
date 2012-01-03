#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>
#include "DrawableComponent.hpp"
#include "Bus.hpp"
#include "FpsCounter.hpp"
#include "TextComponent.hpp"

class Hud : public DrawableComponent
{
public :

    Hud(Game* game);
    ~Hud();
    virtual void update();
    virtual void draw();
    static const std::string FONT_NAME;

private :

    Bus* _bus;
    FpsCounter* _fpsCounter;
    TextComponent* _score;
    TextComponent* _speed;
    TextComponent* _fps;
    std::string convertIntToString(int n);
    std::string convertFloatToString(float n);
};

#endif
