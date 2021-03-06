#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <GL/glut.h>
#include <vector>
#include <string>

#include "ResourceManager.hpp"
#include "InputManager.hpp"
#include "Bus.hpp"
#include "Hud.hpp"
#include "Road.hpp"
#include "FpsCounter.hpp"
#include "TextureManager.hpp"
#include "ParallaxLayer.hpp"
#include "SkyBox.hpp"
#include "Menu.hpp"

class Component;
class DrawableComponent;
class sf::Clock;
class sf::RenderWindow;

class Game
{
public :
    
    static const float INIT_POS;

    Game(std::string title, unsigned int width, unsigned int height, unsigned int colorMode);
    ~Game();
    void run();
    void updateWorld();
    void drawWorld();
    void updateCamera();
    void moveCamera(float z);

    //Getters
    sf::RenderWindow* getApp();
    InputManager* getInputManager();
    Bus* getBus();
    ResourceManager<sf::Image>* getImageManager();
    ResourceManager<sf::Font>* getFontManager();
    ResourceManager<sf::Music>* getMusicManager();
    float getTime();
    std::string getLevel();
    FpsCounter* getFpsCounter();
    float getCameraPosition();
    TextureManager* getTextureManager();
    float getCompletionPercentage();
    Road* getRoad();
    bool isEditing();

    
private :

    void initialize();
    void loadResources();
    void initOpenGL();
    void handleMenuAction(std::string action);

    //Attributes pertaining to the RenderWindow
    std::string _title;
    unsigned int _width;
    unsigned int _height;
    unsigned int _colorMode;
    sf::RenderWindow* _app;
    sf::Clock* _time;

    //Vectors for components
    std::vector<Component*> _components;
    std::vector<DrawableComponent*> _drawableComponents;

    //Managers
    InputManager* _inputManager;
    ResourceManager<sf::Image>* _imageManager;
    ResourceManager<sf::Font>* _fontManager;
    ResourceManager<sf::Music>* _musicManager;
    TextureManager* _textureManager;

    //Other components
    FpsCounter* _fpsCounter;
    
    //Drawable Components
    Bus* _bus;
    Hud* _hud;
    Road* _road;
    ParallaxLayer* _parallaxLayer1;
    SkyBox* _skyBox;
	Menu* _mainMenu;
	Menu* _pauseMenu;

    //Attributes related to the game
    std::string _level;
    float _cameraPosition;
    float _completionPercentage;
	bool _paused;
    bool _editing;
};

#endif
