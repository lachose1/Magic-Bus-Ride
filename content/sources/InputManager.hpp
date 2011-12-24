#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include "Component.hpp"
#include "Game.hpp"

class InputManager : public Component
{
public :
    //InputManager();
    InputManager(Game* game);
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