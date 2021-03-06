#ifndef ROAD_H
#define ROAD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "OpenGLComponent.hpp"
#include "RoadBlock.hpp"
#include "InputManager.hpp"

class Road : public OpenGLComponent
{
public :

    static const int MAX_ROWS = 26;
    static const int LANES = 7;

    void draw();
    void update();
    float getRow();
    int getLength();
    int getColumn();
    bool isSolid(int lane);
    Road(Game* game);
    ~Road();

private :

    void createRoad();
    void drawRoad();
	void createEnvironment();
    void readLength(std::ifstream& stream);
    void loadMap(std::ifstream& stream);
    void writeMap();
    void handleInput();

    std::string _mapName;
    std::vector<std::vector<int> > _map;
    std::vector<std::vector<RoadBlock*> > _blocks;
    int _length;
    float _blockLength;
    InputManager* _inputManager;
    int _column;
};

#endif
