//
//  Settings.h
//  FinalBS
//
//  Created by Alia Hassan  on 12/29/14.
//  Copyright (c) 2014 Alia Hassan . All rights reserved.
//

#ifndef __FinalBS__Settings__
#define __FinalBS__Settings__

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Settings.h"

using namespace sf;

class SettingsW
{
    
    private:
    RenderWindow * name;
    int width;
    int height;
    Settings * set;
    
    Sprite bckgrndImage;
    Texture bckgrndImageTexture;
    
    Sprite cursor;
    Texture cursorTexture;
    
    
    Text pageTitle;
    Text languageTitle;
    Text volumeTitle;
    Text musicTitle;
    Text difficultyTitle;
    Text fontTitle;
    
    vector <Text> languageOptions;
    vector <Text> volumeOptions;
    vector <Text> musicOptions;
    vector <Text> difficultyOptions;
    vector <Text> fontOptions;
    
    
    public:
    SettingsW(RenderWindow* , Settings *);
    ~SettingsW();
    
    void initialize();
    void gameloop();
    bool handleEvents();
    void renderScreen();
    void update();
};

#endif /* defined(__FinalBS__Settings__) */
