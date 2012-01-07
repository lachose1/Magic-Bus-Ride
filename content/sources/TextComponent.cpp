#include "TextComponent.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

TextComponent::TextComponent(Game* game, string text, string fontName, Vector2f position, float size)
    : DrawableComponent(game)
{
    _text = text;
    _fontManager = _game->getFontManager();
    _font = _fontManager->find(fontName);
    _position = position;
    _size = size;

    _string = String(_text, *_font, _size);
    _string.SetPosition(_position);
}

TextComponent::~TextComponent()
{
}

void TextComponent::draw()
{
    _app->Draw(_string);
}

void TextComponent::setText(string text)
{
    _text = text;
    _string.SetText(_text);
}

void TextComponent::update()
{
}

void TextComponent::setPosition(Vector2f position)
{
    _position = position;
    _string.SetPosition(_position);
}

float TextComponent::getWidth()
{
    return _string.GetRect().GetWidth();
}

float TextComponent::getHeight()
{
    return _string.GetRect().GetHeight();
}

Vector2f* TextComponent::getPosition()
{
	return &_position;
}