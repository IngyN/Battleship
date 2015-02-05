
#include <SFML/Graphics.hpp>
#include "Welcome.h"
#include "GameW.h"
#include <cwchar>
#include <cstdlib>
#include <fstream>
using namespace sf;

int main()
{
    srand(unsigned(time(NULL)));
    // Create the main window
    RenderWindow window(sf::VideoMode::getDesktopMode(), "Welcome", Style::Fullscreen);
    
    RenderWindow * w;
    w=&window;

//    Text t; Font f; f.loadFromFile("/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/French/font1.ttf");
//    t.setFont(f);
//    
//    string c;
//    string pageTextSource = "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/SettingsW/SettingsWF8.txt";
//    ifstream in; in.open(pageTextSource.c_str());
//    locale loc ("");
//    in.imbue(loc); getline(in,c); wchar_t ws[c.length()];
//
//   // for (int i=0; i<c.size(); ++i)
//        mbstowcs(ws, c.c_str(), c.length()+1);
//    
//    wstring c1(ws);
    
    // Set the settings here
    
    Settings * S= new Settings;
    S->language="English";
    
 //   Welcome myWindow(w,S);
    
    GameW myGame(w,S);

    system("pause");
    return 0;
}
