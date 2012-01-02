#include "Game.hpp"

using namespace sf;
using namespace std;

Game::Game(string title, unsigned int width, unsigned int height, unsigned int colorMode)
	: _title(title), _width(width), _height(height), _colorMode(colorMode)
{
    initialize();
    _level = "Main Menu";
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

    for(unsigned int i = 0; i < _drawableComponents.size(); ++i)
    {
        delete _drawableComponents[i];
        _drawableComponents[i] = 0;
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

    loadResources();

    initOpenGL();
    _road = new Road(this);
    _drawableComponents.push_back(_road);

    _bus = new Bus(this);
    _drawableComponents.push_back(_bus);
    _hud = new Hud(this);
    _drawableComponents.push_back(_hud);
}

void Game::loadResources()
{
    _imageManager->add("tree.png");
    _imageManager->add("bowser.png");
    _imageManager->add(Bus::IMAGE_NAME);
    roadTexture = loadTexture("road1.png");
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
        //drawOpenGL();
        drawWorld();
        _app->Display();
    }
}

void Game::updateWorld()
{
    for(unsigned int i = 0; i < _components.size(); ++i)
    {
        _components[i]->update();
    }

    for(unsigned int i = 0; i < _drawableComponents.size(); ++i)
    {
        _drawableComponents[i]->update();
    }
}

void Game::drawWorld()
{
    for(unsigned int i = 0; i < _drawableComponents.size(); ++i)
    {
        _drawableComponents[i]->draw();
    }
}

void Game::drawOpenGL()
{		        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        
        glRotatef(_time->GetElapsedTime() * 50, 1.f, 0.f, 0.f); //Ces lignes sont temporaires, juste pour
        glRotatef(_time->GetElapsedTime() * 30, 0.f, 1.f, 0.f); //bien tester l'animation OpenGL
        glRotatef(_time->GetElapsedTime() * 90, 0.f, 0.f, 1.f); //en faisant tourner le cube

	    glBegin(GL_QUADS);

        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f,  50.f, -50.f);
        glVertex3f( 50.f,  50.f, -50.f);
        glVertex3f( 50.f, -50.f, -50.f);

        glVertex3f(-50.f, -50.f, 50.f);
        glVertex3f(-50.f,  50.f, 50.f);
        glVertex3f( 50.f,  50.f, 50.f);
        glVertex3f( 50.f, -50.f, 50.f);

        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f(-50.f,  50.f, -50.f);
        glVertex3f(-50.f,  50.f,  50.f);
        glVertex3f(-50.f, -50.f,  50.f);

        glVertex3f(50.f, -50.f, -50.f);
        glVertex3f(50.f,  50.f, -50.f);
        glVertex3f(50.f,  50.f,  50.f);
        glVertex3f(50.f, -50.f,  50.f);

        glVertex3f(-50.f, -50.f,  50.f);
        glVertex3f(-50.f, -50.f, -50.f);
        glVertex3f( 50.f, -50.f, -50.f);
        glVertex3f( 50.f, -50.f,  50.f);

        glVertex3f(-50.f, 50.f,  50.f);
        glVertex3f(-50.f, 50.f, -50.f);
        glVertex3f( 50.f, 50.f, -50.f);
        glVertex3f( 50.f, 50.f,  50.f);

    glEnd();
}

int Game::loadTexture(string texture) {
    _imageManager->add(texture);

    GLuint textureId;
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGBA, _imageManager->find(texture)->GetWidth(), _imageManager->find(texture)->GetHeight(), GL_RGBA, GL_UNSIGNED_BYTE, _imageManager->find(texture)->GetPixelsPtr());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    return textureId;
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