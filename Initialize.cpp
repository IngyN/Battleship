//
//  Initialize.cpp
//  battleeee
//
//  Created by Gadalla on 12/21/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Initialize.h"

Initialize :: Initialize (RenderWindow * w, Settings S)
{
    name= w; set=S;
    initialize();
    gameloop();
}

void Initialize :: initialize()
{
    // read settings for file / music/ theme/ difficulty
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