#include "TextureManager.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

TextureManager::TextureManager(Game* game)
{
    _imageManager = game->getImageManager();
}

TextureManager::~TextureManager()
{
}

void TextureManager::load(string filename)
{
    _imageManager->add(filename);
    sf::Image* texture = _imageManager->find(filename);

    GLuint textureId;
    glGenTextures(1, &textureId);

    glBindTexture(GL_TEXTURE_2D, textureId);

    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, texture->GetWidth(), texture->GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE,texture->GetPixelsPtr());

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    _textures.insert(std::pair<string, int>(filename, textureId));
}

int TextureManager::find(string filename)
{
    map<string, int>::iterator texture = _textures.find(filename);

    if(texture != _textures.end())
        return texture->second;
    else
        return -1; //Impossible value if the texture does not exist.
}
