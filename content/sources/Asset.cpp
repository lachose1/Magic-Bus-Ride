#include <string>

#include "Asset.hpp"

using namespace std;

template <typename T>
string Asset<T>::getFilename()
{
    return _filename;
}

template<typename T>
T* Asset<T>::getFile()
{
    return &_file;
}