#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

#include "ResourceManager.hpp"
#include "InputManager.hpp"

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
    sf::RenderWindow* getApp();

    InputManager* _inputManager;
    ResourceManager<sf::Image>* _imageManager;
    ResourceManager<sf::Font>* _fontManager;
    ResourceManager<sf::Music>* _musicManager;
    
private :

    void initialize();
    void loadResources();

    std::string _title; //Titre de la fenetre RenderWindow
    unsigned int _width; //Largeur de la fenetre
    unsigned int _height; //Hauteur de la fenetre
    unsigned int _colorMode; //ColorMode de la fenetre
    sf::RenderWindow* _app; //Fenetre SFML du jeu
    sf::Clock* _time; //Temps du jeu en ms
    std::vector<Component*> _components; //Vector des components non-affichables
    std::vector<DrawableComponent*> _drawableComponents; //Vector des components affichables
};

#endif
