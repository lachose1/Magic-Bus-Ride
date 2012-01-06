#include "Game.hpp"

using namespace sf;
using namespace std;

const float Game::INIT_POS = -50.0f;

Game::Game(string title, unsigned int width, unsigned int height, unsigned int colorMode)
	: _title(title), _width(width), _height(height), _colorMode(colorMode)
{
    initialize();
}

Game::~Game()
{
    delete _imageManager;
    delete _fontManager;
    delete _musicManager;
    delete _time;

    unsigned int size;

    size = _components.size();

    for(unsigned int i = 0; i < size; ++i)
    {
        delete _components[i];
        _components[i] = 0;
    }

    size = _drawableComponents.size();

    for(unsigned int i = 0; i < size; ++i)
    {
        delete _drawableComponents[i];
        _drawableComponents[i] = 0;
    }
    
    delete _app;
}

void Game::initialize()
{
    _level = "level1-1";
    _cameraPosition = INIT_POS;
    _app = new RenderWindow(VideoMode(_width, _height, _colorMode), _title);
    _app->SetFramerateLimit(60);

    _time = new Clock();
    _time->Reset();

    _fpsCounter = new FpsCounter(this);
    _components.push_back(_fpsCounter);

    _inputManager = new InputManager(this, _app);
    _components.push_back(_inputManager);

    _imageManager = new ResourceManager<Image>("../res/images/");
    _fontManager = new ResourceManager<Font>("../res/fonts/");
    _musicManager = new ResourceManager<Music>("../res/music/");
    _textureManager = new TextureManager(this);

    loadResources();

    initOpenGL();

    _parallaxLayer1 = new ParallaxLayer(this, "skybox1.png", 1);
    _drawableComponents.push_back(_parallaxLayer1);
    _skyBox = new SkyBox(this);
    _drawableComponents.push_back(_skyBox);
    _road = new Road(this);
    _drawableComponents.push_back(_road);
    _bus = new Bus(this);
    _drawableComponents.push_back(_bus);
    _hud = new Hud(this);
    _drawableComponents.push_back(_hud);
}

void Game::loadResources()
{
    _imageManager->add("skybox1.png");
    _imageManager->add("tree.png");
    _imageManager->add("bowser.png");
    _imageManager->add(Bus::IMAGE_NAME);
    _textureManager->load("road1.png");
    _textureManager->load("grass1.png");
    _textureManager->load("road2.png");
    _textureManager->load("transparent.png");
    _textureManager->load("sky1.png");
    _textureManager->load("desert1.png");
	_textureManager->load("skyscraper1.png");
    _fontManager->add("terminus.ttf");
    _musicManager->add("sixteen.ogg");
    //Uncomment the following to see that find really does work and to hear some music.
    //_musicManager->find("sixteen.ogg")->Play();
}

void Game::initOpenGL()
{
    _app->PreserveOpenGLStates(true); //Pour preserver la 3D de opengl en dessinant des sprites

    // Set color and depth clear value
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 0.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.f, 1.f, 1.f, 500.f);
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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        drawWorld();
        _app->Display();
    }
}

void Game::updateWorld()
{
    updateCamera();

    for(unsigned int i = 0; i < _components.size(); ++i)
        _components[i]->update();

    for(unsigned int i = 0; i < _drawableComponents.size(); ++i)
        _drawableComponents[i]->update();

    _completionPercentage = _road->getRow() / _road->getLength() * 100;
}

void Game::drawWorld()
{
    for(unsigned int i = 0; i < _drawableComponents.size(); ++i)
    {
        _drawableComponents[i]->draw();
    }
}

void Game::updateCamera()
{
    if(!_bus->isAlive())
        _cameraPosition -= 20.0f;
    else if(_bus->isMoving())
        _cameraPosition += _bus->getSpeed() / 10.f;

    if(_cameraPosition < INIT_POS)
        _cameraPosition = INIT_POS;
}

RenderWindow* Game::getApp()
{
    return _app;
}

InputManager* Game::getInputManager()
{
    return _inputManager;
}

ResourceManager<sf::Image>* Game::getImageManager()
{
    return _imageManager;
}

ResourceManager<sf::Font>* Game::getFontManager()
{
    return _fontManager;
}

ResourceManager<sf::Music>* Game::getMusicManager()
{
    return _musicManager;
}

Bus* Game::getBus()
{
    return _bus;
}

float Game::getTime()
{
    return _time->GetElapsedTime();
}

string Game::getLevel()
{
    return _level;
}

FpsCounter* Game::getFpsCounter()
{
    return _fpsCounter;
}

float Game::getCameraPosition()
{
    return _cameraPosition;
}

TextureManager* Game::getTextureManager()
{
    return _textureManager;
}

float Game::getCompletionPercentage()
{
    return _completionPercentage;
}

Road* Game::getRoad()
{
    return _road;
}
