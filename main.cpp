
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
    
    // Set the settings here
    
    Settings * S= new Settings;
    S->language="English";
    Welcome  myWindow (w, S);

    return 0;
}
