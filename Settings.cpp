//
//  Settings.cpp
//  battleeee
//
//  Created by Ingy on 1/13/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "Settings.h"
#include "ResourcePath.hpp"

Settings::Settings ()
{
    language="English";
    fontPathE = resourcePath() + "font1.ttf";
    overallFont.loadFromFile(fontPathE);
    
    //string fontPathA = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/English/font1.ttf";
    fontPathF = resourcePath() + "font4.ttf";
    
    cursorPathE= resourcePath() + "cursor1.png";
    cursorPathF= resourcePath() + "cursor3.png";
    
    cursorTexture.loadFromFile(cursorPathE);
    
    this->difficulty='E';
    
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