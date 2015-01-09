//
//  Settings.cpp
//  FinalBS
//
//  Created by Alia Hassan  on 12/29/14.
//  Copyright (c) 2014 Alia Hassan . All rights reserved.
//

#include "SettingsW.h"
#include "Settings.h"

//#include <SFML/Graphics.hpp>

SettingsW :: SettingsW(RenderWindow* window, Settings * sett)
{
    name =window;
    width = 800;
    height = 600;
    set = sett;
    
    initialize();
    gameloop();
}


SettingsW :: ~SettingsW()
{
    
}



void SettingsW :: initialize()
{
    string bckgrnd = "/Users/Alia/Documents/battleeee/battleeee/data/Images/BackgroundImages/background1.png";
    string cursorImage = "/Users/Alia/Documents/battleeee/battleeee/data/Images/Cursors/cursor.png";
    
    bckgrndImageTexture.loadFromFile(bckgrnd,IntRect(0, 0, 1600, 2560));
    bckgrndImageTexture.setSmooth(true);
    bckgrndImage.setTexture(bckgrndImageTexture);
    
    
    cursorTexture.loadFromFile(cursorImage);
    cursorTexture.setSmooth(true);
    cursor.setTexture(cursorTexture);
    cursor.setPosition(490, 360);
    cursor.setScale(0.42, 0.38);
    
    
    Font pageFont = set->overallFont;
    
    

}

void SettingsW :: gameloop()
{
    bool flag =true;
    
    while (name->isOpen() && flag)
    {
        flag=handleEvents();
        update();
        renderScreen();
    }
}

bool SettingsW :: handleEvents()
{
    bool flag =true; Event event;
    
    while (name -> pollEvent(event) && flag)
    {
        switch(event.type)
        {
            case Event::Closed:
                name->close();
                flag=false;
                break;
                
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                {
                    // name->close(); to be able to come back to the previous page
                    flag=false;
                }
                break;
                
                // case ....
                
        }
    }
    
    return flag;

}

void SettingsW :: renderScreen()
{
    
}

void SettingsW :: update()
{
    
}