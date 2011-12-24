#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>

#include "Game.hpp"

using namespace sf;
using namespace std;

Game::Game(string title, unsigned int width, unsigned int height, unsigned int colorMode)
	: _title(title), _width(width), _height(height), _colorMode(colorMode)
{
    _app = new RenderWindow(VideoMode(_width, _height, _colorMode), _title);
    _app->SetFramerateLimit(60);
    _time.Reset();

    _inputManager = new InputManager(this);
    _components.push_back(_inputManager);

    _imageManager = new ResourceManager<Image>("../res/images/");
    _fontManager = new ResourceManager<Font>("../res/fonts/");
    _musicManager = new ResourceManager<Music>("../res/music/");
}

Game::~Game()
{
    delete _app;
	delete _inputManager;
	delete _imageManager;
	delete _fontManager;
	delete _musicManager;
}

void Game::run()
{
    while(_app->IsOpened())
    {
        Event event;

        while (_app->GetEvent(event))
        {
            if (event.Type == Event::Closed)
                _app->Close();
        }

        _app->Clear();
        _app->Display();
    }
}

RenderWindow* Game::getApp()
{
    return _app;
}