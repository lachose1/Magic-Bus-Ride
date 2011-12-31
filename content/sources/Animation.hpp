#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Animation
{
public :

    Animation(const std::string &filepath, std::string name); //Un constructeur par lequel on peut forcer un filepath pour l'animation
    void createFramesCoordinates(std::vector<sf::IntRect>* rectangles);
    sf::IntRect* nextFrame();
    int getLoops();
    float getCompletion();
    
private :

    int _frames; //Nombre de frames de l'animation
    bool _reverse; //Pour commencer par la fin
    bool _roundTrip; //Pour une animation qui fait un aller-retour dans les frames
    int _loops; //Combien de fois l'animation s'est faite au complet
    sf::IntRect** _framesCoordinates; //Coordonnées de chaque frame
    int _currentFrame; //Le frame à afficher
    std::vector<float> _framesTimes; //Le temps à afficher chaque frame
    int _framesElapsed; //Nombre de frames qui ont passés
    sf::Clock _life; //Temps depuis la creation de lanimation;
};

#endif

