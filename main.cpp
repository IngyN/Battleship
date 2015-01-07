
#include <SFML/Graphics.hpp>
#include "Welcome.h"
#include <iostream>
using namespace sf;

int main()
{
    
    // Create the main window
    RenderWindow window(sf::VideoMode::getDesktopMode(), "Welcome", Style::Fullscreen);
    
    RenderWindow * w;
    w=&window;
    Welcome  myWindow (w);
    
    cout<<window.getSize().x<< window.getSize().y ;

    return 0;
}
