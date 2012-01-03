#include "Hud.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Hud::FONT_NAME = "terminus.ttf";

Hud::Hud(Game* game) : DrawableComponent(game)
{
    _bus = _game->getBus();
    _fpsCounter = _game->getFpsCounter();
    _score = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _speed = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _fps = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
}

Hud::~Hud()
{
}

void Hud::update()
{
    string score = convertIntToString(_bus->getScore());
    string speed = convertIntToString(_bus->getSpeed());
    string fps = convertFloatToString(_fpsCounter->getFps());

    _score->setText(score);
    _speed->setText(speed);
    _fps->setText(fps);

    _speed->setPosition(Vector2f(_app->GetWidth() - _speed->getWidth(), 0));
    _fps->setPosition(Vector2f(_app->GetWidth() - _fps->getWidth(), _app->GetHeight() - _fps->getHeight()));
}

void Hud::draw()
{
    _score->draw();
    _speed->draw();
    _fps->draw();
}

string Hud::convertIntToString(int n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}

string Hud::convertFloatToString(float n)
{
    stringstream ss;
    ss << setiosflags(ios::fixed) << setprecision(0) << n;
    return ss.str();
}