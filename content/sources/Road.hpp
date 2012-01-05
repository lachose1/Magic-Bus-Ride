#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "OpenGLComponent.hpp"
#include "RoadBlock.hpp"

class Road : public OpenGLComponent
{
public :

    static const int LANES = 7;

    void draw();
    void update();
    Road(Game* game);
    ~Road();

private :

    void createRoad();
    void readLength(std::ifstream& stream);
    void loadMap(std::ifstream& stream);

    std::string _mapName;
    std::vector<std::vector<int> > _map;
    RoadBlock* _blockTest;
    RoadBlock* _blockTest2;
    int _length;
};

#endif
