#include "Hud.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Hud::FONT_NAME = "terminus.ttf";

Hud::Hud(Game* game) : DrawableComponent(game)
{
    _bus = _game->getBus();
    _score = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _speed = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
}

Hud::~Hud()
{
}

void Hud::update()
{
    string score = convertIntToString(_bus->getScore());
    string speed = convertIntToString(_bus->getSpeed());

    _score->setText(score);
    _speed->setText(speed);

    _speed->setPosition(Vector2f(_app->GetWidth() - _speed->getWidth(), 0));
}

void Hud::draw()
{
    _score->draw();
    _speed->draw();
}

string Hud::convertIntToString(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}