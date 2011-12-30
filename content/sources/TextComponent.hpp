#ifndef TEXT_COMPONENT_H
#define TEXT_COMPONENT_H

#include <SFML/Graphics.hpp>
#include "DrawableComponent.hpp"
#include "ResourceManager.hpp"

class TextComponent : public DrawableComponent
{
public:

    TextComponent(Game* game, std::string text, std::string fontName, sf::Vector2f position, float size = 30.0f);
    ~TextComponent();
    virtual void draw();
    virtual void update();
    void setText(std::string text);
    float getWidth();
    float getHeight();
    void setPosition(sf::Vector2f position);

private:

    sf::String _string;
    sf::Font* _font;
    std::string _text;
    float _size;
    sf::Vector2f _position;
    ResourceManager<sf::Font>* _fontManager;

};

#endif
