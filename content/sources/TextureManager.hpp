#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include "ResourceManager.hpp"

class Game;

class TextureManager
{
public:
    TextureManager(Game* game);
    ~TextureManager();
    void load(std::string filename);
    int find(std::string filename);

private:
    ResourceManager<sf::Image>* _imageManager;
    std::map<std::string, int> _textures;

};

#endif
