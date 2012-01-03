#include "RoadBlock.hpp"

RoadBlock::RoadBlock(int type, int height) : _type(type), _height(height)
{
}

RoadBlock::~RoadBlock()
{
}

bool RoadBlock::isSolid()
{
    return _solid;
}