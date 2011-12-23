#include <cstdlib>
#include <SFML/Graphics.hpp> 

#include "Game.hpp"

using namespace sf;

int main()
{
    Game magicBusRide("Magic Bus Ride", 800, 600, 32);
    magicBusRide.run();
    
    return EXIT_SUCCESS;
}