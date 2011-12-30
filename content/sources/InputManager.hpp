#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Component.hpp"

class Game;
class sf::RenderWindow;
class sf::Input;

class InputManager : public Component
{
public :
    InputManager(Game* game, sf::RenderWindow* app);
    ~InputManager();
    static const int KEY_COUNT = 6;
    enum KeyName {UP, DOWN, LEFT, RIGHT, SPACE, ESCAPE};
    bool isKeyPressed(KeyName key);
    bool isNewKey(KeyName key);
    virtual void update();

private :
    sf::RenderWindow* _app;
    const sf::Input& _input;
    bool _lastState[KEY_COUNT];
    bool _currentState[KEY_COUNT];
};

#endif