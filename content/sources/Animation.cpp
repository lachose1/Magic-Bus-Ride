#include "Animation.hpp"

using namespace sf;
using namespace std;

Animation::Animation(const std::string &filepath, string name)
    : _frames(0), _reverse(false), _roundTrip(false), _loops(0), _currentFrame(0), _framesElapsed(0)
{
    ifstream animFile(filepath.c_str());
    string line;
    bool found = false;
    int loops = 0;
    vector<IntRect> rectangles;
    
    if(animFile)
    {
        for(int i = 0; getline(animFile, line); i++)
        {
            if(line == name)
                found = true;

            if(found == true)
            {
                if(loops < 4)
                {
                    size_t middle = line.find(":");
                    string reading = line.substr(middle+1);

                    switch(loops)
                    {
                    case 0 :
                        break;
                    case 1 :
                        _frames = atoi(reading.c_str());
                        break;
                    case 2 :
                        if(reading.c_str() == "0")
                            _reverse = false;
                        if(reading.c_str() == "1")
                            _reverse = true;
                        break;
                    case 3 :
                        if(reading.c_str() == "0")
                            _roundTrip = false;
                        if(reading.c_str() == "1")
                            _roundTrip = true;
                        break;
                    }
                }

                if(loops >= 4)
                {
                    size_t middle = line.find(":");
                    string reading = line.substr(middle+1);
                    string values[5];

                    for(int i = 0; i < 5; ++i)
                    {
                        string value = "";
                        size_t virgule = reading.find(",");
                        values[i] = reading.substr(0, virgule);
                        reading.erase(0, virgule + 1);
                    }

                    rectangles.push_back(IntRect(atoi(values[0].c_str()), atoi(values[1].c_str()),
                        atoi(values[2].c_str()), atoi(values[3].c_str())));
                    _framesTimes.push_back(atof(values[4].c_str()));
                }
                loops++;
            }
            if(loops > 4+_frames)
                break;
        }

    }

    animFile.close();
    createFramesCoordinates(&rectangles);
    _life.Reset();
}

void Animation::createFramesCoordinates(vector<IntRect>* rectangles)
{
    _framesCoordinates = new IntRect*[_frames];

    for(int added = 0; added < _frames; added++)
    {
        _framesCoordinates[added] = new IntRect((*rectangles)[added]);
    }
}

IntRect* Animation::nextFrame()
{
    IntRect* currentCoordinates;
    
    if(_currentFrame >= _frames)
    {
        _currentFrame = 0;
        _loops++;
    }

    if(_life.GetElapsedTime() / _framesTimes[_currentFrame] > _framesElapsed)
    {
        ++_framesElapsed;
        currentCoordinates = _framesCoordinates[_currentFrame];
        ++_currentFrame;
    }

    else
        currentCoordinates = _framesCoordinates[_currentFrame];

    return currentCoordinates;
}

int Animation::getLoops()
{
    return _loops;
}

float Animation::getCompletion()
{
    return (float)_framesElapsed / (float)_frames;
}