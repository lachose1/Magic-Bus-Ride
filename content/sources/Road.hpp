#ifndef ROAD_H
#define ROAD_H

#include "OpenGLComponent.hpp"

class Road : public OpenGLComponent
{
public :

    void draw();
    void update();
    Road(Game* game);
    ~Road();

protected:

private :
};

#endif