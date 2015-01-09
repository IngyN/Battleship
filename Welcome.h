//
//  Welcome.h
//  battleeee
//
//  Created by Ingy on 11/24/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Welcome__
#define __battleeee__Welcome__

#include "Settings.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Welcome
{
    
public:
    Welcome (RenderWindow *, Settings *);
    ~Welcome ();
    void initialize();
    void gameloop();
    bool handleEvents();
    void renderScreen();
    void update();
    
private:
    
    RenderWindow * window;
    Settings * set;
    Font mainFont;
    
    Text signedIn;
    Text welcomeText;
    vector <Text> menuItems;
    
    Sprite bgImage;
    Texture bgImageTexture;
    
    Sprite characterImage;
    Texture characterImageTexture;
    
    Sprite cursor;
    Texture cursorTexture;
};
#endif /* defined(__battleeee__Welcome__) */
