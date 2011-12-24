#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Component.hpp"
#include "DrawableComponent.hpp"
#include "InputManager.hpp"
#include "ResourceManager.hpp"
#include "Asset.hpp"

class Component;
class DrawableComponent;
class InputManager;

class Game
{
public :
    
    Game(std::string title, unsigned int width, unsigned int height, unsigned int colorMode);
    ~Game();
    void run();
    sf::RenderWindow* getApp();
    InputManager* _inputManager;
    ResourceManager<sf::Image>* _imageManager;
    ResourceManager<sf::Font>* _fontManager;
    ResourceManager<sf::Music>* _musicManager;
    
private :

    std::string _title; //Titre de la fen�tre RenderWindow
    unsigned int _width; //Largeur de la fen�tre
    unsigned int _height; //Hauteur de la fen�tre
    unsigned int _colorMode; //ColorMode de la fen�tre
    sf::RenderWindow* _app; //Fen�tre SFML du jeu
    sf::Clock _time; //Temps du jeu en ms
    std::vector<Component*> _components; //Vector des components non-affichables
    std::vector<DrawableComponent*> _drawableComponents; //Vector des components affichables
};

#endif
