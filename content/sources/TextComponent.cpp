#include "TextComponent.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

TextComponent::TextComponent(Game* game, string text, string fontName, Vector2f position, float size)
    : DrawableComponent(game), _text(text), _fontManager(_game->getFontManager()), _font(_fontManager->find(fontName)), _position(position), _size(size)
{
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
