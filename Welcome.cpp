//
//  Welcome.cpp
//  battleeee
//
//  Created by Ingy on 11/24/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Welcome.h"
#include "Rules.h"
#include "SettingsW.h"
#include "Initialize.h"
#include <fstream>
#include "ResourcePath.hpp"

// Check last USER for avatar!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

Welcome::Welcome (RenderWindow* window, Settings * s)
{
    this->window = window;
    this->set=s;
    initialize();
    gameloop();
}
Welcome::~Welcome ()
{
    
}

void Welcome::initialize()
{
    string bckg = resourcePath() + "background3.png"; //"/data/Images/BackgroundImages/background3.png"; //"/Users/Ingy/Desktop/battleeee/battleeee/data/Images/BackgroundImages/background3.png";
    string character =  resourcePath() + "Enchantress.png"; //"/data/Images/Avatars/Enemy/Enchantress.png"; //"/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Avatars/Enemy/Enchantress.png";
    string curs = resourcePath() + "cursor1.png"; //"/data/Images/Cursors/cursor1.png"; //"/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Cursors/cursor1.png";
    
    string sourceE= resourcePath() + "WelcomeE.txt"; //data/Text/Welcome/WelcomeE.txt"; // "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/Welcome/WelcomeE.txt";
    string sourceF= resourcePath() + "WelcomeF.txt"; //"/data/Text/Welcome/WelcomeF.txt";// "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/Welcome/WelcomeF.txt";
    
    // Pictures
    
    
    bgImageTexture.loadFromFile(bckg );//, IntRect(0, 0, window->getSize().x /*1600*/, window->getSize().y /*2560*/));
    bgImageTexture.setSmooth(true);
    bgImage.setTexture(bgImageTexture);
    bgImage.setScale(window->getSize().x / double(bgImageTexture.getSize().x) , window->getSize().y / double(bgImageTexture.getSize().y));
    
    characterImageTexture.loadFromFile(character);
    characterImage.setTexture(characterImageTexture);
    characterImage.setPosition(1160, 30);
    characterImage.setScale(0.45, 0.45);
    
    //Cursor
    
    cursorTexture=this->set->cursorTexture;
    cursorTexture.setSmooth(true);
    cursor.setTexture(cursorTexture);
    cursor.setPosition(490, 360);
    cursor.setScale(0.42, 0.38);
    
    // Text
    
    ifstream textSource;
    mainFont=set->overallFont;
    string temp;
    
     menuItems.erase(menuItems.begin(), menuItems.end());
    
    if(set->language=="English") // Load from English file
    {
        textSource.open(sourceE.c_str());
        
        getline(textSource,temp);
        welcomeText.setString(temp);
        
        getline(textSource,temp);
        signedIn.setString(temp);
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
    }
    
    if(set->language=="French") // Load from French file
    {
        textSource.open(sourceF.c_str());
        
        getline(textSource,temp);
        welcomeText.setString(temp);
        
        getline(textSource,temp);
        signedIn.setString(temp);
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
        getline(textSource,temp);
        menuItems.push_back(Text(temp, mainFont));
        
    }
    welcomeText.setFont(mainFont);
    welcomeText.setCharacterSize(60);
    welcomeText.setColor(Color(10,15,80));
    welcomeText.setPosition((window->getSize().x-welcomeText.getLocalBounds().width)/2 , 230) ;
    
    signedIn.setFont(mainFont);
    signedIn.setCharacterSize(25);
    signedIn.setPosition(965, 35);
    signedIn.setColor(Color(10,15,80));
    
    for (int i=0; i<menuItems.size(); i++)
    {
        menuItems[i].setColor(Color(10,15,80));
        menuItems[i].setCharacterSize(40);
        menuItems[i].setPosition( (window->getSize().x - menuItems[i].getLocalBounds().width )/2 /*530*/, 350 + 60 * i);
    }
   
    if(this->set->language=="French")
   {
       menuItems[1].setString(L"RÉGLAGES");
       menuItems[2].setString(L"RÈGLES DU JEU");
   }
}

void Welcome::gameloop()
{
    bool o = true;
    while(window->isOpen() && o)
    {
        o = handleEvents();
        update();
        renderScreen();
    }
}

bool Welcome::handleEvents()
{
    Event event;
    bool o = true;
    while (window->pollEvent(event) && o)
    {
        switch(event.type)
        {
            case Event::KeyPressed:
                if(event.key.code == Keyboard::Escape)
                {
                    o=false;
                }
                if(event.key.code == Keyboard::Down && cursor.getPosition().y <= menuItems.back().getPosition().y)
                {
                    cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y+60);
                }
                if(event.key.code == Keyboard::Up && cursor.getPosition().y >= menuItems[1].getPosition().y)
                {
                    cursor.setPosition(cursor.getPosition().x, cursor.getPosition().y-60);
                }
                if (event.key.code == Keyboard::Return && cursor.getPosition().y == 360+(menuItems.size()-1)*60 )
                {
                    o=false;
                }
                if (event.key.code == Keyboard::Return && cursor.getPosition().y == 360+(menuItems.size()-2)*60 )
                {
                    Rules(this->window, set);
                }
                if (event.key.code == Keyboard::Return && cursor.getPosition().y == 360+(menuItems.size()-3)*60 )
                {
                    SettingsW(this->window, set);
                    initialize();
                }
                if (event.key.code == Keyboard::Return && cursor.getPosition().y == 360+(menuItems.size()-4)*60 )
                {
                    //Initialize(this->window, set);
                }

                // c = (c + 1) % n;
                // c = (c - 1 + n)%n;
                break;
            case Event::Closed:
                o=false;
                break;
        }
    }
    return o;
}

void Welcome::renderScreen()
{
    window->clear();
    
    // Drawing pictures
    
    window->draw(bgImage);
    window->draw(characterImage);
    
    //Drawing cursor
    
    window->draw(cursor);
    
    // Drawing Text
    
    for(int i=0; i<menuItems.size(); i++)
    {
        window->draw(menuItems[i]);
    }
    window->draw(signedIn);
    window->draw(welcomeText);
    
    window->display();
}

void Welcome::update()
{

}