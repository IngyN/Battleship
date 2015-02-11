//
//  Initialize.h
//  battleeee
//
//  Created by Ingy on 12/21/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Initialize__
#define __battleeee__Initialize__

#include "Settings.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Initialize
{
public:
    Initialize(RenderWindow *, Settings *);
    ~Initialize();
    
    void initialize();
    void gameloop();
    bool handleEvents();
    void renderScreen();
    void update();
    
private:
    Settings* set;
    RenderWindow * name;
    Font mainFont;
    Text windowTitle;
    // member for every drawable object
    
    Sprite playerGrid;
    Texture gridTexture;
    
    Sprite backImage;
    Texture backTexture;
    
    
};

#endif /* defined(__battleeee__Initialize__) */
