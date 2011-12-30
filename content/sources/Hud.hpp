#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include "DrawableComponent.hpp"
#include "Bus.hpp"
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
    TextComponent* _score;
    TextComponent* _speed;
    std::string convertIntToString(int n);
};

#endif
