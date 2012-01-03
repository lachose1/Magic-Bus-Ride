#ifndef ROADBLOCK_H
#define ROADBLOCK_H

class RoadBlock
{
public :

    RoadBlock(int type, int height);
    ~RoadBlock();
    bool isSolid();

private :

    int _type;
    int _height;
    bool _solid;
};

#endif