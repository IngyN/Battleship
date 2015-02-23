//
//  gameOver.h
//  battleeee
//
//  Created by Ingy on 2/23/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __battleeee__gameOver__
#define __battleeee__gameOver__

#include "Settings.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class GameOver
{
public:
    GameOver(RenderWindow *, Settings *, bool);
    ~GameOver();
    
    void initialize();
    void gameloop();
    bool handleEvents();
    void renderScreen();
    void update();
    
private:
    
    Settings * S;
    RenderWindow * name;
    
    Font pageFont;
    Text title;
    string textSource;
    
    Texture backTexture;
    Sprite backImage;
    
    Sprite cursor;
    Texture cursorTexture;
    int cursorXpos, cursorYpos;
    
    // member for every drawable object
};

#endif /* defined(__battleeee__gameOver__) */
