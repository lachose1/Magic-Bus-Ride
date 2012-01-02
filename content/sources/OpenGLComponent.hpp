#ifndef OPENGL_COMPONENT_H
#define OPENGL_COMPONENT_H

#include "DrawableComponent.hpp"

class OpenGLComponent : public DrawableComponent
{
public :

    virtual void draw();
    OpenGLComponent(Game* game);
    ~OpenGLComponent();

protected:

};

#endif