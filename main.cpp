
#include <SFML/Graphics.hpp>
#include "Welcome.h"
//#include "SettingsW.h"
#include <iostream>
using namespace sf;

int main()
{
    
    // Create the main window
    RenderWindow window(sf::VideoMode::getDesktopMode(), "Settings", Style::Fullscreen);
    
    RenderWindow * w;
    w=&window;
    
    
    // Set the settings here
    
    Settings * S= new Settings;
    S->language="English";
   // SettingsW  myWindow (w, S);
    Welcome myWindow(w,S);
    system("pause");
    return 0;
}
