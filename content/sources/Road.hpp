#ifndef ROAD_H
#define ROAD_H

#include "OpenGLComponent.hpp"

class Road : public OpenGLComponent
{
public :

    void draw();
    void update();
    void createRoad();
    Road(Game* game);
    ~Road();

protected:

private :
};

#endif