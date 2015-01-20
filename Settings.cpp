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
    fontPathF = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/French/font4.ttf";
    
    cursorPathE="/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Cursors/cursor1.png";
    cursorPathF="/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Cursors/cursor3.png";
    //cursorPathA="/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Cursors/cursor3.png";
    
    cursorTexture.loadFromFile(cursorPathE);
    
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

void Settings:: updateCursor()
{
    if(language=="English")
        cursorTexture.loadFromFile(cursorPathE);
    if(language=="French")
        cursorTexture.loadFromFile(cursorPathF);
    if(language=="Arabic")
        cursorTexture.loadFromFile(cursorPathA);
    
}