//
//  Settings.cpp
//  FinalBS
//
//  Created by Alia Hassan  on 12/29/14.
//  Copyright (c) 2014 Alia Hassan . All rights reserved.
//

#include "SettingsW.h"
#include "Settings.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace sf;

//#include <SFML/Graphics.hpp>

SettingsW :: SettingsW(RenderWindow* window, Settings * sett)
{
    name =window;
    width = 1600;
    height = 2560;
    set = sett;
    
    initialize();
    gameloop();
}


SettingsW :: ~SettingsW()
{
    
}



void SettingsW :: initialize()
{
    string pageTextSource;
    
    if (set->language == "english")
        pageTextSource = "/Users/Alia/Documents/battleeee/battleeee/data/Text/SettingsWEnglish.txt";
    else if (set->language == "french")
        pageTextSource = "/Users/Alia/Documents/battleeee/battleeee/data/Text/SettingsWFrench.txt";
    else if (set->language == "arabic")
        pageTextSource = "/Users/Alia/Documents/battleeee/battleeee/data/Text/SettingsWArabic.txt";
    
    
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
    
    ifstream settTextFile;
    settTextFile.open(pageTextSource);
    string temp;
    
    getline(settTextFile, temp);
    pageTitle.setFont(pageFont);
    pageTitle.setString(temp);
    pageTitle.setCharacterSize(60);
    pageTitle.setColor(Color(10,15,80));
    pageTitle.setPosition((name->getSize().x)/2-135,230) ;
    
    getline(settTextFile, temp);
    languageTitle.setFont(pageFont);
    languageTitle.setString(temp);
    languageTitle.setCharacterSize(60);
    languageTitle.setColor(Color(10,15,80));
    languageTitle.setPosition((name->getSize().x)/2-135,230);
    

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
    name->clear();
    
    // Drawing pictures
    
    name->draw(bckgrndImage);
    
}

void SettingsW :: update()
{
    
}