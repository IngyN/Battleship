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

Rules :: Rules (RenderWindow * w, Settings *S)
{
    name= w; set=S;
    initialize();
    gameloop();
}

void Rules :: initialize()
{
    
    // read settings from file / music/ theme/ difficulty
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
    if (set->language== "English")
        int r=0;
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
                    name->close();
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