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
        pageTextSource = "/Users/Alia/Documents/battleeee/battleeee/data/Text/SettingsW/SettingsWEnglish.txt";
    else if (set->language == "french")
        pageTextSource = "/Users/Alia/Documents/battleeee/battleeee/data/Text/SettingsW/SettingsWFrench.txt";
    else if (set->language == "arabic")
        pageTextSource = "/Users/Alia/Documents/battleeee/battleeee/data/Text/SettingsW/SettingsWArabic.txt";
    
    
    string bckgrnd = "/Users/Alia/Documents/battleeee/battleeee/data/Images/BackgroundImages/background3.png";
    string cursorImage1 = "/Users/Alia/Documents/battleeee/battleeee/data/Images/Cursors/cursor1.png";
    string cursorImage2 = "/Users/Alia/Documents/battleeee/battleeee/data/Images/Cursors/cursor2.png";
    
    bckgrndImageTexture.loadFromFile(bckgrnd,IntRect(0, 0, 1600, 2560));
    bckgrndImageTexture.setSmooth(true);
    bckgrndImage.setTexture(bckgrndImageTexture);
    
    
//    cursorTextureSec.loadFromFile(cursorImage2);
//    cursorTextureSec.setSmooth(true);
//    cursorSec.setTexture(cursorTextureSec);
//    cursorSec.setPosition(490, 360);
//    cursorSec.setScale(0.42, 0.38);
    
    cursorTexture.loadFromFile(cursorImage1);
    cursorTexture.setSmooth(true);
    cursor.setTexture(cursorTexture);
    cursor.setPosition(100, 300);
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
    pageTitle.setPosition((name->getSize().x)/2-135,200) ;
    
    getline(settTextFile, temp, ' ');
    languageTitle.setFont(pageFont);
    languageTitle.setString(temp);
    languageTitle.setCharacterSize(60);
    languageTitle.setColor(Color(10,15,80));
    
    while (settTextFile.peek()!=)
    {
        getline(settTextFile, temp, ' ');
        languageOptions.push_back(Text(temp,pageFont));
        
    }
   
    
    getline(settTextFile, temp, ' ');
    volumeTitle.setFont(pageFont);
    volumeTitle.setString(temp);
    volumeTitle.setCharacterSize(60);
    volumeTitle.setColor(Color(10,15,80));
    
    while (settTextFile.peek()!=)
    {
        getline(settTextFile, temp, ' ');
        volumeOptions.push_back(Text(temp,pageFont));
        
    }
    
    getline(settTextFile, temp, ' ');
    musicTitle.setFont(pageFont);
    musicTitle.setString(temp);
    musicTitle.setCharacterSize(60);
    musicTitle.setColor(Color(10,15,80));
    
    while (settTextFile.peek()!=)
    {
        getline(settTextFile, temp, ' ');
        musicOptions.push_back(Text(temp,pageFont));
        
    }
    
    getline(settTextFile, temp, ' ');
    difficultyTitle.setFont(pageFont);
    difficultyTitle.setString(temp);
    difficultyTitle.setCharacterSize(60);
    difficultyTitle.setColor(Color(10,15,80));
    
    while (settTextFile.peek()!=)
    {
        getline(settTextFile, temp, ' ');
        difficultyOptions.push_back(Text(temp,pageFont));
        
    }
    
    getline(settTextFile, temp, ' ');
    fontTitle.setFont(pageFont);
    fontTitle.setString(temp);
    fontTitle.setCharacterSize(60);
    fontTitle.setColor(Color(10,15,80));
    
    while (settTextFile.peek()!=)
    {
        getline(settTextFile, temp, ' ');
        fontOptions.push_back(Text(temp,pageFont));
        
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    languageTitle.setPosition((name->getSize().x)/2-135,400);
    for(int i=0; i<languageOptions.size(); i++)
    {
        languageOptions[i].setFont(pageFont);
        languageOptions[i].setColor(Color(10,15,80));
        languageOptions[i].setCharacterSize(40);
        languageOptions[i].setPosition((name->getSize().x)/2+100*i, 400);
    }
    
    volumeTitle.setPosition((name->getSize().x)/4-135,600);
    for(int i=0; i<volumeOptions.size(); i++)
    {
        volumeOptions[i].setFont(pageFont);
        volumeOptions[i].setColor(Color(10,15,80));
        volumeOptions[i].setCharacterSize(40);
        volumeOptions[i].setPosition((name->getSize().x)/2+50*i, 600);
    }
    
    musicTitle.setPosition((name->getSize().x)/4-135,800);
    for(int i=0; i<musicOptions.size(); i++)
    {
        musicOptions[i].setFont(pageFont);
        musicOptions[i].setColor(Color(10,15,80));
        musicOptions[i].setCharacterSize(40);
        musicOptions[i].setPosition((name->getSize().x)/2+80*i, 800);    }
    
    difficultyTitle.setPosition((name->getSize().x)/4-135,1000);
    for(int i=0; i<difficultyOptions.size(); i++)
    {
        difficultyOptions[i].setFont(pageFont);
        difficultyOptions[i].setColor(Color(10,15,80));
        difficultyOptions[i].setCharacterSize(40);
        difficultyOptions[i].setPosition((name->getSize().x)/2+100*i, 1000);    }
    
    fontTitle.setPosition((name->getSize().x)/4-135,1200);
    for(int i=0; i<fontOptions.size(); i++)
    {
        fontOptions[i].setFont(pageFont);
        fontOptions[i].setColor(Color(10,15,80));
        fontOptions[i].setCharacterSize(40);
        fontOptions[i].setPosition((name->getSize().x)/2+100*i, 1200);
    }

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
                
                if(event.key.code == Keyboard::Down && cursor.getPosition().y < fontTitle.getPosition().y)
                {
                    cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y+100);
                }
                if(event.key.code == Keyboard::Up && cursor.getPosition().y > languageTitle.getPosition().y)
                {
                    cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y-100);
                }
                
                
                if (event.key.code == Keyboard::Return && cursor.getPosition().y ==languageTitle.getPosition().y)
                {
                    cursor.setPosition(languageOptions[1].getPosition().x- 20, cursor.getPosition().y);
                    
                    switch (event.type)
                   
                    {
                        case Event::KeyPressed:
                            if(event.key.code == Keyboard::Right && cursor.getPosition().x < languageOptions.back().getPosition().x)
                            {
                                cursor.setPosition(cursor.getPosition().x+100, cursor.getPosition().y);
                            }
                            if(event.key.code == Keyboard::Left && cursor.getPosition().x > fontOptions[1].getPosition().x)
                            {
                                cursor.setPosition(cursor.getPosition().x-100, cursor.getPosition().y);
                            }
                            if(event.key.code == Keyboard::Return)
                            {
                                ////WE NEED AN ARRAY OR SOMETHING FOR THE LANGUAGE OPTIONS
                                set->language = languageOptions[(cursor.getPosition().x-name->getSize().x/2)/100].getString();
                                cursor.setPosition(languageTitle.getPosition().x - 20, cursor.getPosition().y);
                            }
                            break;
                            
                        default:
                            break;
                    }
                }
                
                
                
                
                
                
                
                
                
                
                
                
        }
    }
    
    return flag;

}

void SettingsW :: renderScreen()
{
    name->clear();
    
    // Drawing pictures
    
    name->draw(bckgrndImage);
    name->draw(pageTitle);
    name->draw(languageTitle);
    name->draw(volumeTitle);
    name->draw(musicTitle);
    name->draw(difficultyTitle);
    name->draw(fontTitle);
    
    for(int i=0; i<languageOptions.size(); i++)
    {
        name->draw(languageOptions[i]);
    }
    
    for(int i=0; i<volumeOptions.size(); i++)
    {
        name->draw(volumeOptions[i]);
    }
    
    for(int i=0; i<musicOptions.size(); i++)
    {
        name->draw(musicOptions[i]);
    }
    
    for(int i=0; i<difficultyOptions.size(); i++)
    {
        name->draw(difficultyOptions[i]);
    }
    
    for(int i=0; i<fontOptions.size(); i++)
    {
        name->draw(fontOptions[i]);
    }
    
    name->draw(cursor);
    
    name->display();
}

void SettingsW :: update()
{
    
}