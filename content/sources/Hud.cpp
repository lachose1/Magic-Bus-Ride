#include "Hud.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Hud::FONT_NAME = "terminus.ttf";

Hud::Hud(Game* game) : DrawableComponent(game)
{
    _inputManager = _game->getInputManager();
    _bus = _game->getBus();
    _fpsCounter = _game->getFpsCounter();

    _score = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _speed = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _fps = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _percentage = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _cameraPosition = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _row = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));
    _column = new TextComponent(_game, "0", FONT_NAME, Vector2f(0,0));

    _devEnabled = false;
}

Hud::~Hud()
{
}

void Hud::update()
{
    if(_inputManager->isNewKey(InputManager::DEV))
        _devEnabled = !_devEnabled;

    string score = convertIntToString(_bus->getScore());
    string speed = convertFloatToString(_bus->getSpeed());
    _score->setText(score);
    _speed->setText(speed);
    _speed->setPosition(Vector2f(_app->GetWidth() - _speed->getWidth(), 0));

    if(_devEnabled)
    {
        string fps = convertFloatToString(_fpsCounter->getFps());
        string percentage = convertFloatToString(_game->getCompletionPercentage());
        string cameraPosition = convertFloatToString(_game->getCameraPosition());
        string row = convertFloatToString(_game->getRoad()->getRow());
        string column = convertIntToString(_game->getRoad()->getColumn());

        _fps->setText(fps);
        _percentage->setText(percentage + "%");
        _cameraPosition->setText(cameraPosition);
        _row->setText(row);
        _column->setText(column);

        _fps->setPosition(Vector2f(_app->GetWidth() - _fps->getWidth(), _app->GetHeight() - _fps->getHeight()));
        _percentage->setPosition(Vector2f(0, _app->GetHeight() - _percentage->getHeight()));
        _cameraPosition->setPosition(Vector2f(_percentage->getWidth() + 40, _app->GetHeight() - _cameraPosition->getHeight()));
        _row->setPosition(Vector2f(_percentage->getWidth() + 40, _app->GetHeight() - _row->getHeight()));
        _column->setPosition(Vector2f(_percentage->getWidth() + _row->getWidth() + 80, _app->GetHeight() - _column->getHeight()));
    }
    
}

void Hud::draw()
{
    _score->draw();
    _speed->draw();
    if(_devEnabled)
    {
        _fps->draw();
        _percentage->draw();
        //_cameraPosition->draw();
        _row->draw();
        _column->draw();
    }
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