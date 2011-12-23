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

    std::string _title; //Titre de la fen�tre RenderWindow
    unsigned int _width; //Largeur de la fen�tre
    unsigned int _height; //Hauteur de la fen�tre
    unsigned int _colorMode; //ColorMode de la fen�tre
    sf::RenderWindow* _app; //Fen�tre SFML du jeu
    sf::Event _event; //Event sur la fen�tre
};

#endif
