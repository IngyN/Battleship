//
//  Rules.h
//  battleeee
//
//  Created by Ingy on 1/4/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __battleeee__Rules__
#define __battleeee__Rules__

#include "Settings.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Rules
{
public:
    Rules(RenderWindow *, Settings);
    ~Rules();
    
    void initialize();
    void gameloop();
    bool handleEvents();
    void renderScreen();
    void update();
    
private:
    int width, height;
    Settings set;
    RenderWindow * name;
    
    // member for every drawable object
};
#endif /* defined(__battleeee__Rules__) */
