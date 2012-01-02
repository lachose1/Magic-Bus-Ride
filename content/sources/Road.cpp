#include "Road.hpp"
#include "Game.hpp"

using namespace std;

Road::Road(Game* game) : OpenGLComponent(game)
{
}

Road::~Road()
{
}

void Road::draw()
{
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(_game->getTime() * 50, 1.f, 0.f, 0.f); //Ces lignes sont temporaires, juste pour
        glRotatef(_game->getTime() * 30, 0.f, 1.f, 0.f); //bien tester l'animation OpenGL
        glRotatef(_game->getTime() * 90, 0.f, 0.f, 1.f); //en faisant tourner le cube
        createRoad();
}

void Road::update()
{
}

void Road::createRoad()
{
    glBegin(GL_QUADS);
        
        //Front
        glVertex3f(-50.f,  10.f,  75.f);
        glVertex3f( 50.f,  10.f,  75.f);
        glVertex3f( 50.f, -10.f,  75.f);
        glVertex3f(-50.f, -10.f,  75.f);

        //Right
        glVertex3f( 50.f,  10.f,  75.f);
        glVertex3f( 50.f,  10.f, -75.f);
        glVertex3f( 50.f, -10.f, -75.f);
        glVertex3f( 50.f, -10.f,  75.f);

        //Back
        glVertex3f( 50.f,  10.f, -75.f);
        glVertex3f(-50.f,  10.f, -75.f);
        glVertex3f(-50.f, -10.f, -75.f);
        glVertex3f( 50.f, -10.f, -75.f);

        //Left
        glVertex3f(-50.f,  10.f, -75.f);
        glVertex3f(-50.f,  10.f,  75.f);
        glVertex3f(-50.f, -10.f, -75.f);
        glVertex3f(-50.f, -10.f, -75.f);

        //Top
        glVertex3f(-50.f,  10.f, -75.f);
        glVertex3f( 50.f,  10.f, -75.f);
        glVertex3f( 50.f,  10.f,  75.f);
        glVertex3f(-50.f,  10.f,  75.f);

        //Bottom
        glVertex3f(-50.f, -10.f,  75.f);
        glVertex3f( 50.f, -10.f,  75.f);
        glVertex3f( 50.f, -10.f, -75.f);
        glVertex3f(-50.f, -10.f, -75.f);

    glEnd();
}