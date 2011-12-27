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
    //InputManager();
    InputManager(Game* game, sf::RenderWindow* app);
    ~InputManager();
    static const int KEY_COUNT = 5;
    enum KeyName {UP, DOWN, LEFT, RIGHT, SPACE};
    bool isKeyPressed(KeyName key);
    bool isNewKey(KeyName key);
    virtual void update();

private :
    sf::RenderWindow* _app;
    const sf::Input& _input;
    bool lastState[KEY_COUNT];
    bool currentState[KEY_COUNT];
};

#endif