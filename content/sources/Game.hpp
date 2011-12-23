#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Component.hpp"
#include "DrawableComponent.hpp"

class Component;
class DrawableComponent;

class Game
{
public :
    
    Game(std::string title, unsigned int width, unsigned int height, unsigned int colorMode);
    ~Game();
    void run();
    sf::RenderWindow* getApp();
    
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
