#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "Game.hpp"
#include "Component.hpp"
#include "DrawableComponent.hpp"

using namespace sf;
using namespace std;

Game::Game(string title, unsigned int width, unsigned int height, unsigned int colorMode)
	: _title(title), _width(width), _height(height), _colorMode(colorMode)
{
    _app = new RenderWindow(VideoMode(_width, _height, _colorMode), _title);
    _app->SetFramerateLimit(60);
    _time.Reset();
}

Game::~Game()
{
    delete _app;
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