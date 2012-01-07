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

InputManager::~InputManager()
{
    delete _app;
}

void InputManager::update()
{
    for(int i = 0; i < KEY_COUNT; ++i)
        _lastState[i] = _currentState[i];

    _currentState[UP] = _input.IsKeyDown(sf::Key::W) || _input.IsKeyDown(sf::Key::Up);
    _currentState[DOWN] = _input.IsKeyDown(sf::Key::S) || _input.IsKeyDown(sf::Key::Down);
    _currentState[LEFT] = _input.IsKeyDown(sf::Key::A) || _input.IsKeyDown(sf::Key::Left);
    _currentState[RIGHT] = _input.IsKeyDown(sf::Key::D) || _input.IsKeyDown(sf::Key::Right);
    _currentState[SPACE] = _input.IsKeyDown(sf::Key::Space);
    _currentState[ESCAPE] = _input.IsKeyDown(sf::Key::Escape);
    _currentState[F1] = _input.IsKeyDown(sf::Key::F1);
    _currentState[F2] = _input.IsKeyDown(sf::Key::F2);
    _currentState[P] = _input.IsKeyDown(sf::Key::P);
    _currentState[S] = _input.IsKeyDown(sf::Key::S);
    _currentState[NUM0] = _input.IsKeyDown(sf::Key::Num0) || _input.IsKeyDown(sf::Key::Numpad0);
    _currentState[NUM1] = _input.IsKeyDown(sf::Key::Num1) || _input.IsKeyDown(sf::Key::Numpad1);
    _currentState[NUM2] = _input.IsKeyDown(sf::Key::Num2) || _input.IsKeyDown(sf::Key::Numpad2);
}

bool InputManager::isKeyPressed(KeyName key)
{
    return _currentState[key];
}

bool InputManager::isNewKey(KeyName key)
{
    return !_lastState[key] && _currentState[key];
}
