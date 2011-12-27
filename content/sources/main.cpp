#include <cstdlib>

#include "Game.hpp"

using namespace std;
using namespace sf;

int main()
{
    Game magicBusRide("Magic Bus Ride", 800, 600, 32);
    magicBusRide.run();
    
    return EXIT_SUCCESS;
}