#include "Game.hpp"

using namespace sf;
using namespace std;

Game::Game(string title, unsigned int width, unsigned int height, unsigned int colorMode)
	: _title(title), _width(width), _height(height), _colorMode(colorMode)
{
    initialize();
    loadResources();
}

Game::~Game()
{
    delete _imageManager;
    delete _fontManager;
    delete _musicManager;
    delete _time;

    for(unsigned int i = 0; i < _components.size(); ++i)
    {
        delete _components[i];
        _components[i] = 0;
    }
    
    delete _app;
}

void Game::initialize()
{
    _app = new RenderWindow(VideoMode(_width, _height, _colorMode), _title);
    _app->SetFramerateLimit(60);

    _time = new Clock();
    _time->Reset();

    _inputManager = new InputManager(this, _app);
    _components.push_back(_inputManager);

    _imageManager = new ResourceManager<Image>("../res/images/");
    _fontManager = new ResourceManager<Font>("../res/fonts/");
    _musicManager = new ResourceManager<Music>("../res/music/");
}

void Game::loadResources()
{
    _imageManager->add("tree.png");
    _imageManager->add("bowser.png");
    _fontManager->add("terminus.ttf");
    _musicManager->add("sixteen.ogg");
    //Uncomment the following to see that find really does work and to hear some music.
    //_musicManager->find("sixteen.ogg")->Play();
}

void Game::run()
{
    while(_app->IsOpened())
    {
        Event event;

        while (_app->GetEvent(event))
        {
            if (event.Type == Event::Closed || _inputManager->isKeyPressed(InputManager::ESCAPE))
                _app->Close();
        }

        updateWorld();
        _app->Clear();
        drawWorld();
        _app->Display();
    }
}

void Game::updateWorld()
{
    for(unsigned int i = 0; i < _components.size(); i++)
    {
        _components[i]->update();
    }

    for(unsigned int i = 0; i < _drawableComponents.size(); i++)
    {
        _drawableComponents[i]->update();
    }
}

void Game::drawWorld()
{
    _drawableComponents.push_back(new Bus(this, _imageManager->find("bowser.png")));
    for(unsigned int i = 0; i < _drawableComponents.size(); i++)
    {
        _app->Draw(*(_drawableComponents[i]->draw()));
    }
}

RenderWindow* Game::getApp()
{
    return _app;
}