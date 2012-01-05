#ifndef SKYBOX_H
#define SKYBOX_H

#include "DrawableComponent.hpp"

class SkyBox : DrawableComponent
{
public :

    SkyBox(Game* game, std::string skyImage, std::string groundImage);
    ~SkyBox();
    void update();
    void draw();

private :

    sf::Image* _skyImage;
    sf::Image* _groundImage;
    sf::Sprite _skySprite;
    sf::Sprite _groundSprite;
};

#endif
