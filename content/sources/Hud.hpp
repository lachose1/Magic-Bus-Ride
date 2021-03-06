#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iomanip>
#include "DrawableComponent.hpp"
#include "Bus.hpp"
#include "FpsCounter.hpp"
#include "TextComponent.hpp"
#include "InputManager.hpp"

class Hud : public DrawableComponent
{
public :

    Hud(Game* game);
    ~Hud();
    virtual void update();
    virtual void draw();
    static const std::string FONT_NAME;

private :

    InputManager* _inputManager;
    Bus* _bus;
    FpsCounter* _fpsCounter;
    TextComponent* _score;
    TextComponent* _speed;
    TextComponent* _fps;
    TextComponent* _percentage;
    TextComponent* _cameraPosition;
    TextComponent* _row;
    TextComponent* _column;
    std::string convertIntToString(int n);
    std::string convertFloatToString(float n);
    bool _devEnabled;
};

#endif
