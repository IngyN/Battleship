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

SettingsW :: SettingsW(RenderWindow* window, Settings * sett)
{
    name = window;
    width = 1600;
    height = 2560;
    set = sett;
    defaultSize=35;
    up=down=right=left=true;
    count=0;
    hidden=false;
    
    initialize();
    gameloop();
}


SettingsW :: ~SettingsW()
{
    
}



void SettingsW :: initialize()
{
    string pageTextSource;
    
    if (set->language == "English")
        pageTextSource = "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/SettingsW/SettingsWE.txt";
    else if (set->language == "French")
        pageTextSource = "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/SettingsW/SettingsWF.txt";
    else if (set->language == "Arabic")
        pageTextSource = "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/SettingsW/SettingsWA.txt";
    
    languageOptions.erase(languageOptions.begin(),languageOptions.end());
    volumeOptions.erase(volumeOptions.begin(), volumeOptions.end());
    musicOptions.erase(musicOptions.begin(), musicOptions.end());
    fontOptions.erase(fontOptions.begin(), fontOptions.end());
    difficultyOptions.erase(difficultyOptions.begin(),difficultyOptions.end());
    
<<<<<<< HEAD
    string bckgrnd = "/Users/Ingy/Desktop/battleeee/battleeee/data/Images/BackgroundImages/background3.png";
    string cursorImage = "/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Cursors/cursor1.png";
=======
    string bckgrnd = "/Users/Alia/Documents/battleeee/battleeee/data/Images/BackgroundImages/background3.png";
    string cursorImage1 = "/Users/Alia/Documents/battleeee/battleeee/data/Images/Cursors/cursor1.png";
    string cursorImage2 = "/Users/Alia/Documents/battleeee/battleeee/data/Images/Cursors/cursor2.png";
>>>>>>> FETCH_HEAD
    
    bckgrndImageTexture.loadFromFile(bckgrnd);
    bckgrndImageTexture.setSmooth(true);
    bckgrndImage.setTexture(bckgrndImageTexture);
    
<<<<<<< HEAD
    pageFont = set->overallFont;
=======
    
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
>>>>>>> FETCH_HEAD
    
    ifstream settTextFile;
    settTextFile.open(pageTextSource);
    string temp;
    
    getline(settTextFile, temp);
    pageTitle.setFont(pageFont);
    for(int i=0; i<temp.size();i++)
    {
        temp[i]=toupper(temp.at(i));
    }
    pageTitle.setString(temp);
    pageTitle.setCharacterSize(60);
    pageTitle.setColor(Color(10,15,80));
    pageTitle.setPosition((name->getSize().x)/2-135,150) ;
    
    getline(settTextFile, temp, ' ');
    languageTitle.setFont(pageFont);
    for(int i=0; i<temp.size();i++)
    {
        temp[i]=toupper(temp[i]);
    }
    languageTitle.setString(sf::String(temp));
    languageTitle.setCharacterSize(35);
    languageTitle.setColor(Color(10,15,80));
    
    char c;
    settTextFile.get(c);
    while (c != '\n')
    {
        settTextFile.unget();
        settTextFile>>temp; // >> or getline??
        for(int i=0; i<temp.size();i++)
        {
            temp[i]=toupper(temp[i]);
        }
        languageOptions.push_back(Text(temp,pageFont));
        settTextFile.get(c);
    }
    //settTextFile.unget();
    
    getline(settTextFile, temp, ' ');
    volumeTitle.setFont(pageFont);
    for(int i=0; i<temp.size();i++)
    {
        temp[i]=toupper(temp[i]);
    }
    volumeTitle.setString(temp);
    volumeTitle.setCharacterSize(35);
    volumeTitle.setColor(Color(10,15,80));
    
    settTextFile.get(c);
    while (c!='\n')
    {
        settTextFile.unget();
        settTextFile>>temp;
        volumeOptions.push_back(Text(temp,pageFont));
        settTextFile.get(c);
    }
    //settTextFile.unget();
    
    getline(settTextFile, temp, ' ');
    musicTitle.setFont(pageFont);
    for(int i=0; i<temp.size();i++)
    {
        temp[i]=toupper(temp[i]);
    }
    musicTitle.setString(temp);
    musicTitle.setCharacterSize(35);
    musicTitle.setColor(Color(10,15,80));
    
    settTextFile.get(c);
    while (c!='\n')
    {
        settTextFile.unget();
        settTextFile>>temp;
        for(int i=0; i<temp.size();i++)
        {
            temp[i]=toupper(temp[i]);
        }
        musicOptions.push_back(Text(temp,pageFont));
        settTextFile.get(c);
    }
    
    //settTextFile.unget();
    
    getline(settTextFile, temp, ' ');
    difficultyTitle.setFont(pageFont);
    for(int i=0; i<temp.size();i++)
    {
        temp[i]=toupper(temp[i]);
    }
    difficultyTitle.setString(temp);
    difficultyTitle.setCharacterSize(35);
    difficultyTitle.setColor(Color(10,15,80));
    
    settTextFile.get(c);
    
    while (c!='\n')
    {
        settTextFile.unget();
        settTextFile>>temp;
        for(int i=0; i<temp.size();i++)
        {
            temp[i]=toupper(temp[i]);
        }
        difficultyOptions.push_back(Text(temp,pageFont));
        settTextFile.get(c);
        
    }
    
    //settTextFile.unget();
    
    getline(settTextFile, temp, ' ');
    fontTitle.setFont(pageFont);
    for(int i=0; i<temp.size();i++)
    {
        temp[i]=toupper(temp[i]);
    }
    fontTitle.setString(temp);
    fontTitle.setCharacterSize(35);
    fontTitle.setColor(Color(10,15,80));
    
    settTextFile.get(c);
    while (c!='\n'&& c!=EOF)
    {
        settTextFile.unget();
        settTextFile>>temp;
        fontOptions.push_back(Text(temp,pageFont));
        settTextFile.get(c);
    }
    
    //////////////////////////////////////////////////////////////////////////////////////////////////////
    
    // Positions
    int xOffset=200; int yOffset=275; int step= 60;
    languageTitle.setPosition(xOffset,yOffset);
    for(int i=0; i<languageOptions.size(); i++)
    {
        languageOptions[i].setFont(pageFont);
        languageOptions[i].setColor(Color(10,15,80));
        languageOptions[i].setCharacterSize(35);
        languageOptions[i].setPosition(xOffset+350+220*i, yOffset);
    }
    
    volumeTitle.setPosition(xOffset,yOffset+step);
    for(int i=0; i<volumeOptions.size(); i++)
    {
        volumeOptions[i].setFont(pageFont);
        volumeOptions[i].setColor(Color(10,15,80));
        volumeOptions[i].setCharacterSize(35);
        volumeOptions[i].setPosition(xOffset+350+40*i,volumeTitle.getPosition().y);
    }
    
    musicTitle.setPosition(xOffset, yOffset+step*2);
    for(int i=0; i<musicOptions.size(); i++)
    {
        musicOptions[i].setFont(pageFont);
        musicOptions[i].setColor(Color(10,15,80));
        musicOptions[i].setCharacterSize(35);
        musicOptions[i].setPosition(xOffset+350+220*i, musicTitle.getPosition().y);
    }
    
    difficultyTitle.setPosition(xOffset,yOffset+step*3);
    for(int i=0; i<difficultyOptions.size(); i++)
    {
        difficultyOptions[i].setFont(pageFont);
        difficultyOptions[i].setColor(Color(10,15,80));
        difficultyOptions[i].setCharacterSize(35);
        difficultyOptions[i].setPosition(xOffset+350+220*i, difficultyTitle.getPosition().y);    }
    
    fontTitle.setPosition(xOffset,yOffset+step*4);
    for(int i=0; i<fontOptions.size(); i++)
    {
        fontOptions[i].setFont(pageFont);
        fontOptions[i].setColor(Color(10,15,80));
        fontOptions[i].setCharacterSize(35);
        fontOptions[i].setPosition(xOffset+350+40*i, fontTitle.getPosition().y);
    }
    
    cursorTexture.loadFromFile(cursorImage);
    cursorTexture.setSmooth(true);
    cursor.setTexture(cursorTexture);
    cursor.setPosition(languageTitle.getPosition().x-40, languageTitle.getPosition().y+5);
    cursor.setScale(0.40, 0.34);
    
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
                if(event.key.code == Keyboard::Down && cursor.getPosition().y <= fontTitle.getPosition().y && down)
                {
                    cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y+60);
                }
                if(event.key.code == Keyboard::Up && cursor.getPosition().y > languageTitle.getPosition().y+5 && up)
                {
                    cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y-60);
                }
                
                // Languages
                
                // Choosing
                
                if(event.key.code == Keyboard::Return  && cursor.getPosition().y==languageTitle.getPosition().y+9 && cursor.getPosition().x >= languageOptions[0].getPosition().x-40 && !up)
                {
                    cout<< "HERE"<<endl;
                    
                    if(count==1)
                    {
                        set->language="French";
                        count=0;
                        initialize();
                    }
                    else if(count==0)
                    {
                        set->language="English";
                        count=0;
                        initialize();
                    }
                }
                
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == languageTitle.getPosition().x-40 && cursor.getPosition().y==languageTitle.getPosition().y+5)
                {
                    cursor.setPosition(cursor.getPosition().x+350, cursor.getPosition().y+4); up=down=false; right=left=true;
                    languageOptions[count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Right && cursor.getPosition().x > languageTitle.getPosition().x-40 && cursor.getPosition().x<languageOptions.back().getPosition().x-40 && right && cursor.getPosition().y==languageTitle.getPosition().y+9)
                {
                    cursor.setPosition(cursor.getPosition().x+220, cursor.getPosition().y);
                    languageOptions[count].setCharacterSize(defaultSize);
                    languageOptions[++count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Left && cursor.getPosition().x >= languageTitle.getPosition().x-40 && left && cursor.getPosition().y==languageTitle.getPosition().y+9)
                {
                    if(count>0)
                    {
                        cursor.setPosition(cursor.getPosition().x-220, cursor.getPosition().y);
                        languageOptions[count].setCharacterSize(defaultSize);
                        languageOptions[--count].setCharacterSize(defaultSize+7);
                    }
                    else
                    {
                        left=right=false; up=down=true;
                        cursor.setPosition(cursor.getPosition().x-350, cursor.getPosition().y-4);
                        languageOptions[count].setCharacterSize(defaultSize);
                        count=0;
                    }
                }
                
                // Volume
                
                // Choosing
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == languageTitle.getPosition().x-40 && cursor.getPosition().y==volumeTitle.getPosition().y+5)
                {
                    cursor.setPosition(cursor.getPosition().x+350, cursor.getPosition().y+4); up=down=false; right=left=true;
                    volumeOptions[count].setCharacterSize(defaultSize+7); hidden=true;
                }
                if(event.key.code == Keyboard::Right && cursor.getPosition().x > languageTitle.getPosition().x-40 && cursor.getPosition().x<volumeOptions.back().getPosition().x-40 && right && cursor.getPosition().y==volumeTitle.getPosition().y+9)
                {
                    cursor.setPosition(cursor.getPosition().x+40, cursor.getPosition().y);
                    volumeOptions[count].setCharacterSize(defaultSize);
                    volumeOptions[++count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Left && cursor.getPosition().x >= languageTitle.getPosition().x-40 && left && cursor.getPosition().y==volumeTitle.getPosition().y+9)
                {
                    if(count>0)
                    {
                        cursor.setPosition(cursor.getPosition().x-40, cursor.getPosition().y);
                        volumeOptions[count].setCharacterSize(defaultSize);
                        volumeOptions[--count].setCharacterSize(defaultSize+7);
                    }
                    else
                    {
                        left=right=false; up=down=true;
                        cursor.setPosition(cursor.getPosition().x-350, cursor.getPosition().y-4);
                        volumeOptions[count].setCharacterSize(defaultSize);
                        count=0; hidden =false;
                    }
                }
                
                // reinitializing the screen
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == volumeOptions[count].getPosition().x-40 && cursor.getPosition().y==volumeTitle.getPosition().y+5)
                {
                    // set->volume=count+1; // No mute??
                    // initialize();
                }
                
                // Music
                
                // Choosing
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == languageTitle.getPosition().x-40 && cursor.getPosition().y==musicTitle.getPosition().y+5)
                {
                    cursor.setPosition(cursor.getPosition().x+350, cursor.getPosition().y+4); up=down=false; right=left=true;
                    musicOptions[count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Right && cursor.getPosition().x > languageTitle.getPosition().x-40 && cursor.getPosition().x<musicOptions.back().getPosition().x-40 && right && cursor.getPosition().y==musicTitle.getPosition().y+9)
                {
                    cursor.setPosition(cursor.getPosition().x+220, cursor.getPosition().y);
                    musicOptions[count].setCharacterSize(defaultSize);
                    musicOptions[++count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Left && cursor.getPosition().x >= languageTitle.getPosition().x-40 && left && cursor.getPosition().y==musicTitle.getPosition().y+9)
                {
                    if(count>0)
                    {
                        cursor.setPosition(cursor.getPosition().x-220, cursor.getPosition().y);
                        musicOptions[count].setCharacterSize(defaultSize);
                        musicOptions[--count].setCharacterSize(defaultSize+7);
                    }
                    else
                    {
                        left=right=false; up=down=true;
                        cursor.setPosition(cursor.getPosition().x-350, cursor.getPosition().y-4);
                        musicOptions[count].setCharacterSize(defaultSize);
                        count=0;
                    }
                }
                
                // reinitializing the screen
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == musicOptions[count].getPosition().x-40 && cursor.getPosition().y==musicTitle.getPosition().y+5)
                {
                    // set->music=count+1; // No mute??
                    // initialize();
                }
                
                // Difficulty
                
                // Choosing
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == languageTitle.getPosition().x-40 && cursor.getPosition().y==difficultyTitle.getPosition().y+5)
                {
                    cursor.setPosition(cursor.getPosition().x+350, cursor.getPosition().y+4); up=down=false; right=left=true;
                    difficultyOptions[count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Right && cursor.getPosition().x > languageTitle.getPosition().x-40 && cursor.getPosition().x<difficultyOptions.back().getPosition().x-40 && right && cursor.getPosition().y==difficultyTitle.getPosition().y+9)
                {
                    cursor.setPosition(cursor.getPosition().x+220, cursor.getPosition().y);
                    difficultyOptions[count].setCharacterSize(defaultSize);
                    difficultyOptions[++count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Left && cursor.getPosition().x >= languageTitle.getPosition().x-40 && left && cursor.getPosition().y==difficultyTitle.getPosition().y+9)
                {
                    if(count>0)
                    {
                        cursor.setPosition(cursor.getPosition().x-220, cursor.getPosition().y);
                        difficultyOptions[count].setCharacterSize(defaultSize);
                        difficultyOptions[--count].setCharacterSize(defaultSize+7);
                    }
                    else
                    {
                        left=right=false; up=down=true;
                        cursor.setPosition(cursor.getPosition().x-350, cursor.getPosition().y-4);
                        difficultyOptions[count].setCharacterSize(defaultSize);
                        count=0;
                    }
                }
                
                // reinitializing the screen
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == difficultyOptions[count].getPosition().x-40 && cursor.getPosition().y==difficultyTitle.getPosition().y+5)
                {
                    // set->difficulty=difficultyOptions[count] // No mute??
                    // initialize();
                }
                
                // Font Size
                
                // Choosing
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == languageTitle.getPosition().x-40 && cursor.getPosition().y==fontTitle.getPosition().y+5)
                {
                    cursor.setPosition(cursor.getPosition().x+350, cursor.getPosition().y+4); up=down=false; right=left=true;
                    fontOptions[count].setCharacterSize(defaultSize+7); hidden=true;
                }
                if(event.key.code == Keyboard::Right && cursor.getPosition().x > languageTitle.getPosition().x-40 && cursor.getPosition().x<fontOptions.back().getPosition().x-40 && right && cursor.getPosition().y==fontTitle.getPosition().y+9)
                {
                    cursor.setPosition(cursor.getPosition().x+40, cursor.getPosition().y);
                    fontOptions[count].setCharacterSize(defaultSize);
                    fontOptions[++count].setCharacterSize(defaultSize+7);
                }
                if(event.key.code == Keyboard::Left && cursor.getPosition().x >= languageTitle.getPosition().x-40 && left && cursor.getPosition().y==fontTitle.getPosition().y+9)
                {
                    if(count>0)
                    {
                        cursor.setPosition(cursor.getPosition().x-40, cursor.getPosition().y);
                        fontOptions[count].setCharacterSize(defaultSize);
                        fontOptions[--count].setCharacterSize(defaultSize+7);
                    }
                    else
                    {
                        left=right=false; up=down=true;
                        cursor.setPosition(cursor.getPosition().x-350, cursor.getPosition().y-4);
                        fontOptions[count].setCharacterSize(defaultSize);
                        count=0; hidden =false;
                    }
                }
                
                // reinitializing the screen
                if(event.key.code == Keyboard::Return && cursor.getPosition().x == fontOptions[count].getPosition().x-40 && cursor.getPosition().y==fontTitle.getPosition().y+5)
                {
                    // set->font=count+1; // No mute??
                    // initialize();
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
    
    //Titles
    name->draw(pageTitle);
    
    // Options
    name->draw(languageTitle);
    for(int i=0; i<languageOptions.size(); i++)
    {
        name->draw(languageOptions[i]);
    }
    
    name->draw(volumeTitle);
    for(int i=0; i<volumeOptions.size(); i++)
    {
        name->draw(volumeOptions[i]);
    }
    
    name->draw(musicTitle);
    for(int i=0; i<musicOptions.size(); i++)
    {
        name->draw(musicOptions[i]);
    }
    
    name->draw(difficultyTitle);
    for(int i=0; i<difficultyOptions.size(); i++)
    {
        name->draw(difficultyOptions[i]);
    }
    
    name->draw(fontTitle);
    for(int i=0; i<fontOptions.size(); i++)
    {
        name->draw(fontOptions[i]);
    }
    
    if(!hidden)
        name->draw(cursor);
    
    name->display();
}

void SettingsW :: update()
{
    
}