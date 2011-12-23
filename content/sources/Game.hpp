#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Game
{
public :
    
    Game(std::string title, unsigned int width, unsigned int height, unsigned int colorMode);
    ~Game();
    void run();
    
private :

    std::string _title; //Titre de la fenêtre RenderWindow
    unsigned int _width; //Largeur de la fenêtre
    unsigned int _height; //Hauteur de la fenêtre
    unsigned int _colorMode; //ColorMode de la fenêtre
    sf::RenderWindow* _app; //Fenêtre SFML du jeu
    sf::Event _event; //Event sur la fenêtre
};

#endif
