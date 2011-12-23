#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <vector>
#include <string>

#include "Asset.hpp"

template <typename T>
class ResourceManager
{
public:
    ResourceManager(std::string path);
    ~ResourceManager();
    void add(std::string filename);
    T* find(std::string filename)
    {
        for(int i = 0; i < _resources.size(); ++i)
            if(_resources[i].getFilename() == filename)
                return _resources[i].getFile;

        return NULL;
    }

private:
    std::vector<Asset<T> > _resources;
    std::string _path;
};

#endif
