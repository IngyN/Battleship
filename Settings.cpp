//
//  Settings.cpp
//  battleeee
//
//  Created by Ingy on 1/13/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "Settings.h"

Settings::Settings ()
{
    language="English";
    fontPathE = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/English/font1.ttf";
    overallFont.loadFromFile(fontPathE);
    
    //string fontPathA = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/English/font1.ttf";
    fontPathF = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/French/font3.ttf";
    
}
Settings::~Settings ()
{
    
}

void Settings:: updateFont()
{
    if(language=="English")
        overallFont.loadFromFile(fontPathE);
    if(language=="French")
        overallFont.loadFromFile(fontPathF);
    if(language=="Arabic")
        overallFont.loadFromFile(fontPathA);
        
}