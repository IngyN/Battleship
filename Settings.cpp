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
    string fontPath = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/font1.ttf";
    overallFont.loadFromFile(fontPath);
    
}
Settings::~Settings ()
{
    
}