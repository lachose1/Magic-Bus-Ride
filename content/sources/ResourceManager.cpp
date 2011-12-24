#include <vector>
#include <string>

#include "Asset.hpp"
#include "ResourceManager.hpp"

using namespace std;

template <typename T>
ResourceManager<T>::ResourceManager(string path) : _path(path)
{
}

template <typename T>
ResourceManager<T>::ResourceManager()
{
}

template <typename T>
ResourceManager<T>::~ResourceManager()
{
}

template <typename T>
void ResourceManager<T>::add(string filename)
{
    _resources.push_back(Asset<T>(filename, _path));
}

