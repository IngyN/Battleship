//
//  Rules.cpp
//  battleeee
//
//  Created by Ingy on 1/4/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "Rules.h"

const string BACKGROUND = "backgroundRules.png";
const string RULES_E = "RulesE.txt";
const string RULES_F = "RulesF.txt";
const string RULES_A = "RulesA.txt";
const string RULES_M = "RulesMusic.ogg";

Rules :: Rules (RenderWindow * w, Settings * S)
{
    name= w;
    this->S=S;
    initialize();
    gameloop();
}

Rules :: ~ Rules()
{
    
}
void Rules :: initialize()
{
    // read settings from file / music/ theme/ difficulty
    
    const string BACKGROUND = "backgroundRules.png";
    const string RULES_E = "RulesE.txt";
    const string RULES_F = "RulesF.txt";
    const string RULES_A = "RulesA.txt";
    const string RULES_M = "RulesMusic.ogg";
    
    string Tfont = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/font3.ttf";
    string back = "/Users/Ingy/Desktop/battleeee/battleeee/data/Images/BackgroundImages/background1.png";
    string curs = "/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Cursors/cursor2.png";
    
    backTexture.loadFromFile(back);
    backImage.setTexture(backTexture);
    
    if (S->language== "English")
    {
        // open english
        titleFont.loadFromFile(Tfont);
        
        title.setFont(titleFont);
        title.setCharacterSize(45);
        title.setString("RULES");
        title.setPosition((name->getSize().x)/2-100, 100);
        
        backText.setFont(titleFont);
        backText.setCharacterSize(40);
        backText.setString("BACK");
        backText.setPosition(90,50);
    }
    
    cursorTexture.loadFromFile(curs);
    cursor.setTexture(cursorTexture);
    cursor.setPosition(50,backText.getPosition().y+5);
    cursor.setScale(0.42, 0.38);
    cursorXpos = cursor.getPosition().x;
    cursorYpos =cursor.getPosition().y; // text +5
}

void Rules :: gameloop()
{
    bool flag =true;
    
    while (name->isOpen() && flag)
    {
        flag=handleEvents();
        update();
        renderScreen();
    }
}

void Rules:: renderScreen()
{
    this->name->clear();
    
    // pictures
    name->draw(backImage);
    
    //Text
    name->draw(title);
    name->draw(backText);
    
    //cursor
    name->draw(cursor);
    this->name->display();
}

bool Rules :: handleEvents()
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
                    flag=false;
                }
                if (event.key.code == Keyboard::Return && cursor.getPosition().y == backText.getPosition().y+5)
                {
                    flag=false;
                }
                break;
                
                // case ....
                
        }
    }
    
    return flag;
}

void Rules :: update()
{
    // animations not linked to the user
}