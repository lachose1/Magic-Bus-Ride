#ifndef ROAD_H
#define ROAD_H

#include "OpenGLComponent.hpp"
#include "RoadBlock.hpp"

class Road : public OpenGLComponent
{
public :

    void draw();
    void update();
    void loadMap();
    void createRoad();
    Road(Game* game);
    ~Road();

protected:

private :

    std::string _mapName;
    std::vector<int**> _map;
    RoadBlock* _blockTest;
    RoadBlock* _blockTest2;

};

#endif