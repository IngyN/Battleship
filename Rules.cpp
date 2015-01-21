//
//  Rules.cpp
//  battleeee
//
//  Created by Ingy on 1/4/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "Rules.h"
#include <fstream>
#include <iostream>

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
    const string RULES_E = "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/Rules/RulesE.txt";
    const string RULES_F = "/Users/Ingy/Desktop/battleeee/battleeee/data/Text/Rules/RulesF.txt";
    const string RULES_A = "RulesA.txt";
    const string RULES_M = "RulesMusic.ogg";
    
    string Tfont = "/Users/Ingy/Desktop/battleeee/battleeee/data/Fonts/English/font2.ttf";
    string back = "/Users/Ingy/Desktop/battleeee/battleeee/data/Images/BackgroundImages/background7.png";
    string curs = "/Users/Ingy/Desktop/battleeee/battleeee/data/Images/Cursors/cursor2.png";
    
    backTexture.loadFromFile(back);
    backImage.setTexture(backTexture);
    
    rules.erase(rules.begin(), rules.end());
    ifstream in;
    
    pageFont=S->overallFont;
    //pageFont.loadFromFile(Tfont);
    
    if (S->language== "English")
    {
        // open english
        in.open(RULES_E);
        title.setFont(pageFont);
        title.setCharacterSize(50);
        title.setString("RULES");
        title.setPosition((name->getSize().x)/2-120, 100);
        title.setColor(Color(10,15,80));
        
        backText.setFont(pageFont);
        backText.setCharacterSize(40);
        backText.setString("BACK");
        backText.setPosition(90,50);
        backText.setColor(Color(10,15,80));

        
    }
    else if(S->language== "French")
    {
        in.open(RULES_F);
        title.setFont(pageFont);
        title.setCharacterSize(50);
        title.setString(L"RÈGLES DU JEU");
        title.setPosition((name->getSize().x)/2-120, 100);
        title.setColor(Color(10,15,80));
        
        backText.setFont(pageFont);
        backText.setCharacterSize(40);
        backText.setString("REVENIR");
        backText.setPosition(90,50);
        backText.setColor(Color(10,15,80));
    }
    
    // Getting the text
    
    string temp;
    getline (in, temp);
    do
    {
        for(int i=0; i<temp.size(); i++)
            if(isalpha(temp[i]))
                temp[i]=toupper(temp[i]);
        
        rules.push_back(Text(temp, pageFont));
        getline (in, temp);
        
    }while(temp!="END");
    
    in.close();

    for(int i=0; i<rules.size();i++)
    {
        rules[i].setPosition(50, 200+30*i);
        rules[i].setCharacterSize(22);
        rules[i].setScale(0.92, 1);
        rules[i].setColor(Color::White);
    }
    
    cursorTexture=this->S->cursorTexture;
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
    
    for(int i=0; i<rules.size();i++)
    {
        name->draw(rules[i]);
    }
    
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