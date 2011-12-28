#ifndef ASSET_H
#define ASSET_H

#include <SFML/Audio.hpp>
#include <string>

template <typename T>
class Asset
{
public:

    Asset(std::string filename, std::string path) : _filename(filename) //Constructeur pour Image, Font, SoundBuffer, etc.
    {
        if(!_file.LoadFromFile(path + filename))
            exit(EXIT_FAILURE);
    }

    ~Asset()
    {
    }

    inline std::string getFilename()
    {
        return _filename;
    }

    inline T* getFile()
    {
        return &_file;
    }

private:

    T _file;
    std::string _filename;
};

template <>
class Asset<sf::Music>
{
public:

    Asset(std::string filename, std::string path) : _filename(filename)
    {
        if(!_file.OpenFromFile(path + filename)) //OpenFromFile au lieu de LoadFromFile. Seule différence. Laurent, fuck you.
            exit(EXIT_FAILURE);
    }

    ~Asset()
    {
    }

    inline std::string getFilename()
    {
        return _filename;
    }

    inline sf::Music* getFile()
    {
        return &_file;
    }

private:

    sf::Music _file;
    std::string _filename;
};

#endif
