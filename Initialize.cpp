//
//  Initialize.cpp
//  battleeee
//
//  Created by Gadalla on 12/21/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Initialize.h"
#include "ResourcePath.hpp"
#include "Settings.h"
#include <fstream>

Initialize :: Initialize (RenderWindow * w, Settings * S)
{
    name= w; set=S;
    initialize();
    gameloop();
}

Initialize :: ~Initialize ()
{
}

void Initialize :: initialize()
{
    // read settings for file / music/ theme/ difficulty
    backTexture.loadFromFile(resourcePath() + "/background2.png"); //("/Users/Ingy/Desktop/battleeee/battleeee/data/Images/BackgroundImages/background2.png");
    backImage.setTexture(backTexture);
    
    gridTexture.loadFromFile(resourcePath() + "/board.png"); //("/Users/Ingy/Downloads/board.png");
    
    playerGrid.setTexture(gridTexture);
    playerGrid.setScale(1.5, 1.5);
    playerGrid.setPosition(name->getSize().x/2-gridTexture.getSize().x,name->getSize().y/3-gridTexture.getSize().y);
    
    mainFont=set->overallFont;
    
    string titleTextE = resourcePath() + "InitializeE";
    string titleTextF = resourcePath() + "InitializeF";
    ifstream titleSt;
    string title;
    
    if(set->language=="English") // Load from English file
    {
        titleSt.open(titleTextE.c_str());
        
        getline(titleSt,title);
        windowTitle.setString(title);
    
        
    }
    
    if(set->language=="French") // Load from French file
    {
        titleSt.open(titleTextF.c_str());
        
        getline(titleSt,title);
        windowTitle.setString(title);
    }
    
    
    
}

void Initialize :: gameloop()
{
    bool flag =true;
    
    while (name->isOpen() && flag)
    {
        flag=handleEvents();
        update();
        renderScreen();
    }
}

void Initialize:: renderScreen()
{
    name->clear();
    
    name->draw(backImage);
    
    name->draw(playerGrid);
    
    name->display();
}

bool Initialize :: handleEvents()
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

void Initialize :: update()
{
    // animations not linked to the user
}