#ifndef SKYBOX_H
#define SKYBOX_H

#include "OpenGLComponent.hpp"

class SkyBox : public OpenGLComponent
{
public :

    SkyBox(Game* game);
    ~SkyBox();
    void update();
    void draw();

private :

    int _skyTexture;
    int _groundTexture;
};

#endif
