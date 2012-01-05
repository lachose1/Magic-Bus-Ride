#include "SkyBox.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

SkyBox::SkyBox(Game* game, string skyImage, string groundImage) : DrawableComponent(game)
{

    _skyImage = _game->getImageManager()->find(skyImage);
    _groundImage = _game->getImageManager()->find(groundImage);
    _skySprite.SetImage(*_skyImage);
    _groundSprite.SetImage(*_groundImage);
}

SkyBox::~SkyBox()
{
    delete _skyImage;
    delete _groundImage;
}

void SkyBox::draw()
{
    _app->Draw(_skySprite);
    _app->Draw(_groundSprite);
}

void SkyBox::update()
{
}