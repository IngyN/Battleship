
#include <SFML/Graphics.hpp>
#include "Welcome.h"
#include <iostream>
using namespace sf;

int main()
{
    
    // Create the main window
    RenderWindow window(sf::VideoMode(2560, 1600), "Welcome");
    
    RenderWindow * w;
    w=&window;
    Welcome  myWindow (w);

    return 0;
}
