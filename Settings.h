//
//  Settings.h
//  battleeee
//
//  Created by Ingy on 12/21/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef battleeee_Settings_h
#define battleeee_Settings_h

#include <string>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Settings
{
    
    //What shall the default settings be ?
    
public:
    Settings ();
    ~Settings ();
    void updateFont();
    string language = "English";
    int volume;
    int music;
    string theme;
    char difficulty;
    
    Font overallFont;
    string fontPathF,fontPathE,fontPathA;
    // current User??

};

#endif
