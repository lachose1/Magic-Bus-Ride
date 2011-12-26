#include <SFML/Graphics.hpp>

#include "InputManager.hpp"

using namespace sf;
using namespace std;

InputManager::InputManager(Game* game)
	: Component(game), _app(game->getApp()), _input(_app->GetInput())
{
    for(int i = 0; i < KEY_COUNT; ++i)
    {
        lastState[i] = false;
        currentState[i] = false;
    }
}

//InputManager::InputManager()
//{
//}

InputManager::~InputManager()
{
    delete _app;
    delete[] &lastState;
    delete[] &currentState;
}

void InputManager::update()
{
    for(int i = 0; i < KEY_COUNT; ++i)
        lastState[i] = currentState[i];

    if(_input.IsKeyDown(sf::Key::W) || _input.IsKeyDown(sf::Key::Up))
        currentState[UP] = true;
    if(_input.IsKeyDown(sf::Key::S) || _input.IsKeyDown(sf::Key::Down))
        currentState[DOWN] = true;
    if(_input.IsKeyDown(sf::Key::A) || _input.IsKeyDown(sf::Key::Left))
        currentState[LEFT] = true;
    if(_input.IsKeyDown(sf::Key::D) || _input.IsKeyDown(sf::Key::Right))
        currentState[RIGHT] = true;
    if(_input.IsKeyDown(sf::Key::Space))
        currentState[SPACE] = true;
}

bool InputManager::isKeyPressed(KeyName key)
{
    return currentState[key];
}

bool InputManager::isNewKey(KeyName key)
{
    return !lastState[key] && currentState[key];
}
