#include "SkyBox.hpp"
#include "Game.hpp"

using namespace std;
using namespace sf;

SkyBox::SkyBox(Game* game) : OpenGLComponent(game)
{
    _skyTexture = _game->getTextureManager()->find("sky1.png");
    _groundTexture = _game->getTextureManager()->find("desert1.png");
}

SkyBox::~SkyBox()
{
}

void SkyBox::draw()
{
    float maxView = _game->getCameraPosition() / 40.f;
    for(int j = 0; j < 100; j++)
    {
        for(int i = 0; i < 20; i++)
        {
            //glEnable(GL_TEXTURE_2D);
            //glBindTexture(GL_TEXTURE_2D, _skyTexture);

            //glBegin(GL_QUADS);

            //    //Sky
            //    glTexCoord2f(0.0f, 1.0f);
            //    glVertex3f(-200.f+i*40.f,  100.f, 200.f-j*20.f);
            //    glTexCoord2f(1.0f, 1.0f);
            //    glVertex3f(-160.f+i*40.f,  100.f, 200.f-j*20.f);
            //    glTexCoord2f(1.0f, 0.0f);
            //    glVertex3f(-160.f+i*40.f,  100.f, 180.f-j*20.f);
            //    glTexCoord2f(0.0f, 0.0f);
            //    glVertex3f(-200.f+i*40.f,  100.f, 180.f-j*20.f);

            //glEnd();

            glBindTexture(GL_TEXTURE_2D, _groundTexture);

            glBegin(GL_QUADS);

                //Ground
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-400.f+i*40.f, -50.f, 200.f-j*20.f);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(-360.f+i*40.f, -50.f, 200.f-j*20.f);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(-360.f+i*40.f, -50.f, 180.f-j*20.f);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-400.f+i*40.f, -50.f, 180.f-j*20.f);

            glEnd();
        }
    }
}

void SkyBox::update()
{
}