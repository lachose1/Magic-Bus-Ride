#include "Bus.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

const string Bus::IMAGE_NAME = "bowser.png";
const float Bus::JUMP_ACCEL = -0.4f;
const float Bus::ACCELERATION = 15.0f;
const float Bus::SHADOW_SIZE = 13.0f;
const float Bus::BLINK_INTERVAL = 0.25f;
const float Bus::BLINK_MAX = 1.0f;

Bus::Bus(Game* game) : SpriteComponent(game, IMAGE_NAME)
{
    _speed = 0;
    _score = 0;
    _jumpElapsed = 0;
    _blinkElapsed = 0;
    _jumping = false;
    _alive = true;
    _blinking = false;

    _inputManager = _game->getInputManager();
    _app = _game->getApp();

    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling1on7"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling2on7"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling3on7"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling4on7"));
    _animations.push_back(new Animation("../res/animations/bowser.ani", "rolling5on7"));
	_animations.push_back(new Animation("../res/animations/bowser.ani", "rolling6on7"));
	_animations.push_back(new Animation("../res/animations/bowser.ani", "rolling7on7"));

    _lane = 3;
    setSubRect();
    
    resetPosition();
}

Bus::~Bus()
{
}

void Bus::update()
{
    if(_game->getCameraPosition() == Game::INIT_POS && !_alive)
    {
        _alive = true;
        _blinking = true;
    }
    if(!_jumping && isOnHole())
        _alive = false;

    float x = _position.x;

    if(_alive && !_blinking)
        handleInput(x);

    if(_speed > MAX_SPEED)
        _speed = MAX_SPEED;
    else if(_speed < 0)
        _speed = 0;

    if(isInBounds(x))
    {
        _position.x = x;
        _sprite.SetPosition(_position);
        setLane();
        setSubRect();
    }

    if(_jumping)
        jump();
    if(_blinking)
        blink();

    if(!_alive)
    {
        _speed = 0;
        resetPosition();
    }
}

void Bus::resetPosition()
{
    _position = Vector2f(_app->GetWidth()/2.0f - _sprite.GetSize().x/2.0f,
    LOWER_BOUND - _sprite.GetSize().y);

    _sprite.SetPosition(_position);
}

void Bus::handleInput(float& x)
{
    float time = _app->GetFrameTime();

    if(_inputManager->isKeyPressed(InputManager::UP))
        _speed += ACCELERATION * time;
    if(_inputManager->isKeyPressed(InputManager::DOWN))
        _speed -= ACCELERATION * time;
    if(_inputManager->isKeyPressed(InputManager::LEFT))
        x -= SPEED_X * time;
    if(_inputManager->isKeyPressed(InputManager::RIGHT))
        x += SPEED_X * time;
    if(_inputManager->isNewKey(InputManager::JUMP) && !_jumping)
        _jumping = true;
}

void Bus::draw()
{
    if(_alive && !_game->isEditing())
    {
        drawShadow();
        drawCollisionSquare();
        _app->Draw(_sprite);
    }
}

void Bus::drawShadow()
{
    float currentShadowSize = SHADOW_SIZE*(_position.y/550);
    float shadowX = _position.x/2+currentShadowSize*1.125;
    float shadowAlpha = 50.f+_position.y/5.0;
    float centerValue = currentShadowSize/2-((currentShadowSize/2)*0.20);

    Shape shadow = Shape::Circle(shadowX, 550.f, currentShadowSize, Color(0, 0, 0, shadowAlpha));
    shadow.SetCenter(centerValue, centerValue);
    shadow.SetScale(2, 1); 
    _app->Draw(shadow);
}

void Bus::drawCollisionSquare()
{
    float z = _game->getCameraPosition()+10.f;
    glBegin(GL_QUADS);
        glColor3f(0.5f, 0.0f, 1.0f);
        glVertex3f(-20.f, 20.f, -z);
        glVertex3f( 20.f, 20.f, -z);
        glVertex3f( 20.f, 10.f, -z);
        glVertex3f(-20.f, 10.f, -z);
        glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();
}

void Bus::jump()
{
    float y = _position.y;
    float height = _sprite.GetSize().y;

    y -= JUMP_SPEED * _jumpElapsed + 0.5f * JUMP_ACCEL * _jumpElapsed * _jumpElapsed;
    ++_jumpElapsed;

    if(y + height > LOWER_BOUND)
    {
        y = LOWER_BOUND - height;
        _jumping = false;
        _jumpElapsed = 0;
    }

    _position.y = y;
    _sprite.SetPosition(_position);
}

void Bus::blink()
{
    _blinkElapsed += _app->GetFrameTime();

    if(_blinkElapsed < BLINK_INTERVAL)
        _sprite.SetColor(Color(255, 255, 255, 255));
    else if(_blinkElapsed < 2 * BLINK_INTERVAL)
        _sprite.SetColor(Color(255, 255, 255, 0));
    else if(_blinkElapsed < 3 * BLINK_INTERVAL)
        _sprite.SetColor(Color(255, 255, 255, 255));
    else if(_blinkElapsed < BLINK_MAX)
        _sprite.SetColor(Color(255, 255, 255, 0));
    else
    {
        _sprite.SetColor(Color(255, 255, 255, 255));
        _blinkElapsed = 0.0f;
        _blinking = false;
    }
}

void Bus::setLane()
{
    _lane = (int)(_sprite.GetPosition().x + (_sprite.GetSize().x / 2) - VOID_WIDTH) / LANE_WIDTH;
    if(_lane > 6)
        _lane = 6;
}

void Bus::setSubRect()
{
    _sprite.SetSubRect(*(_animations[_lane]->nextFrame()));
}

bool Bus::isInBounds(float x)
{
    return x >= 0 && (x + _sprite.GetSize().x) <= _app->GetWidth();
}

bool Bus::isMoving()
{
    return _speed > 0;
}

bool Bus::isJumping()
{
    return _jumping;
}

int Bus::getLane()
{
    return _lane;
}

int Bus::getSpeed()
{
    return _speed;
}

int Bus::getScore()
{
    return _score;
}

bool Bus::isAlive()
{
    return _alive;
}

bool Bus::isOnHole()
{
    bool onHole = !_game->getRoad()->isSolid(_lane);
    bool outOfRoad = (_position.x + _sprite.GetSize().x / 2) < VOID_WIDTH ||
        (_position.x + _sprite.GetSize().x / 2) > (_app->GetWidth() - VOID_WIDTH);

    return onHole || outOfRoad;
}
