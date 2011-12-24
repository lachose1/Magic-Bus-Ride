#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "InputManager.hpp"
#include "ResourceManager.hpp"

class Component;
class DrawableComponent;

class Game
{
public :
    
    Game(std::string title, unsigned int width, unsigned int height, unsigned int colorMode);
    ~Game();
    void run();
    sf::RenderWindow* getApp();
    //InputManager _inputManager;
    ResourceManager<sf::Image> _imageManager;
    ResourceManager<sf::Font> _fontManager;
    ResourceManager<sf::Music> _musicManager;
    
private :

    std::string _title; //Titre de la fenêtre RenderWindow
    unsigned int _width; //Largeur de la fenêtre
    unsigned int _height; //Hauteur de la fenêtre
    unsigned int _colorMode; //ColorMode de la fenêtre
    sf::RenderWindow* _app; //Fenêtre SFML du jeu
    sf::Clock _time; //Temps du jeu en ms
    std::vector<Component*> _components; //Vector des components non-affichables
    std::vector<DrawableComponent*> _drawableComponents; //Vector des components affichables
};

#endif
