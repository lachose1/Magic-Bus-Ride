#include "InputManager.hpp"

using namespace sf;
using namespace std;

InputManager::InputManager(Game* game, RenderWindow* app)
	: Component(game), _app(app), _input(_app->GetInput())
{
    for(int i = 0; i < KEY_COUNT; ++i)
    {
        _lastState[i] = false;
        _currentState[i] = false;
    }
}

//InputManager::InputManager()
//{
//}

InputManager::~InputManager()
{
    delete _app;
}

void InputManager::update()
{
    for(int i = 0; i < KEY_COUNT; ++i)
        _lastState[i] = _currentState[i];

    if(_input.IsKeyDown(sf::Key::W) || _input.IsKeyDown(sf::Key::Up))
        _currentState[UP] = true;
    if(_input.IsKeyDown(sf::Key::S) || _input.IsKeyDown(sf::Key::Down))
        _currentState[DOWN] = true;
    if(_input.IsKeyDown(sf::Key::A) || _input.IsKeyDown(sf::Key::Left))
        _currentState[LEFT] = true;
    if(_input.IsKeyDown(sf::Key::D) || _input.IsKeyDown(sf::Key::Right))
        _currentState[RIGHT] = true;
    if(_input.IsKeyDown(sf::Key::Space))
        _currentState[SPACE] = true;
    if(_input.IsKeyDown(sf::Key::Escape))
        _currentState[ESCAPE] = true;
}

bool InputManager::isKeyPressed(KeyName key)
{
    return _currentState[key];
}

bool InputManager::isNewKey(KeyName key)
{
    return !_lastState[key] && _currentState[key];
}
