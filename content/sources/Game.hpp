#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

#include "ResourceManager.hpp"
#include "InputManager.hpp"
#include "Bus.hpp"
#include "Hud.hpp"

class Component;
class DrawableComponent;
class sf::Clock;
class sf::RenderWindow;

class Game
{
public :
    
    Game(std::string title, unsigned int width, unsigned int height, unsigned int colorMode);
    ~Game();
    void run();
    void updateWorld();
    void drawWorld();

    //Getters
    sf::RenderWindow* getApp();
    InputManager* getInputManager();
    Bus* getBus();
    ResourceManager<sf::Image>* getImageManager();
    ResourceManager<sf::Font>* getFontManager();
    ResourceManager<sf::Music>* getMusicManager();
    
private :

    void initialize();
    void loadResources();

    //Attributes pertaining to the RenderWindow
    std::string _title;
    unsigned int _width;
    unsigned int _height;
    unsigned int _colorMode;
    sf::RenderWindow* _app;
    sf::Clock* _time;

    //Vectors for components
    std::vector<Component*> _components;
    std::vector<DrawableComponent*> _drawableComponents;

    //Managers
    InputManager* _inputManager;
    ResourceManager<sf::Image>* _imageManager;
    ResourceManager<sf::Font>* _fontManager;
    ResourceManager<sf::Music>* _musicManager;
    
    //Drawable Components
    Bus* _bus;
    Hud* _hud;
};

#endif
