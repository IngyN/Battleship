//
//  Welcome.cpp
//  battleeee
//
//  Created by Ingy on 11/24/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Welcome.h"



//hellllooooooo

Welcome::Welcome (RenderWindow* window)
{
    this->window = window;
    initialize();
    gameloop();
}
Welcome::~Welcome ()
{
    
}

void Welcome::initialize()
{
    string bckg = "/Users/Ingy/Desktop/battleeee/battleeee/data/Images/BackgroundImages/background8.png";
    string font = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/WelcomeFontTest.ttf";
    string character ="/Users/Ingy/Desktop/battleeee/battleeee/data/Images/sprites/Enemy/Female/Dragoness.png";
    
    mainFont.loadFromFile(font);
    welcomeText.setFont(mainFont);
    welcomeText.setString("Helloooooooo");
    welcomeText.setCharacterSize(30);
    
    bgImageTexture.loadFromFile(bckg,IntRect(0, 0, 1600, 2560));
    bgImageTexture.setSmooth(true);
    bgImage.setTexture(bgImageTexture);

    characterImageTexture.loadFromFile(character);
    characterImage.setTexture(characterImageTexture);

    menuItems.push_back(Text("New Game", mainFont));
    menuItems.push_back(Text("Options", mainFont));
    menuItems.push_back(Text("Rules", mainFont));
    menuItems.push_back(Text("Exit Game", mainFont));
    
    for (int i=0; i<menuItems.size(); i++)
    {
        menuItems[i].setColor(Color(255,255,255));
        menuItems[i].setCharacterSize(30);
        menuItems[i].setPosition(700, 300 + 50 * i);
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
    
    window->draw(bgImage);
    window->draw(characterImage);
    
    for(int i=0; i<menuItems.size(); i++)
    {
        window->draw(menuItems[i]);
    }
    
    window->draw(welcomeText);
    
    window->display();
}

void Welcome::update()
{
    
}