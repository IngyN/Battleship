//
//  GameOver.cpp
//  battleeee
//
//  Created by Ingy on 2/23/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "GameOver.h"
#include <fstream>
#include <iostream>
#include "ResourcePath.hpp"

GameOver :: GameOver (RenderWindow * w, Settings * S, bool won)
{
    name= w;
    this->S=S;
    if(won)
    {
        if (S->language=="English")
            textSource=resourcePath()+"GameOverTextWonE.txt";
        else if (S->language=="French")
            textSource=resourcePath()+"GameOverTextWonF.txt";
        //  else if (S->language=="Arabic")
        //      textSource=resourcePath()+"GameOverTextWonA.txt";
    }
    else{
        if (S->language=="English")
            textSource=resourcePath()+"GameOverTextLostE.txt";
        else if (S->language=="French")
            textSource=resourcePath()+"GameOverTextLostF.txt";
        // else if (S->language=="Arabic")
        //   textSource=resourcePath()+"GameOverTextWonA.txt";
    }
    initialize();
    gameloop();
}

GameOver :: ~ GameOver()
{
    
}
void GameOver :: initialize()
{
    // read settings from file / music/ theme/ difficulty
    
    string back = resourcePath()+"background7.png";
    string curs = resourcePath()+"cursor2.png";
    
    backTexture.loadFromFile(back);
    backImage.setTexture(backTexture);
    
    ifstream in;
    
    pageFont=S->overallFont;
    string temp;
    
    if (S->language== "English")
    {
        // open english
        in.open(textSource.c_str());
        getline (in, temp);
        
        backText.setString("BACK");
        
    }
    else if(S->language== "French")
    {
        in.open(textSource.c_str());
        getline (in, temp);
        
        backText.setString("REVENIR");
        
    }
    
    title.setFont(pageFont);
    title.setCharacterSize(50);
    title.setString(temp);
    title.setPosition((name->getSize().x)/2-180, 100);
    title.setColor(Color(10,15,80));
    
    backText.setPosition(90,50);
    backText.setColor(Color(10,15,80));
    backText.setFont(pageFont);
    backText.setCharacterSize(40);
    in.close();
    
    
    //    cursorTexture=this->S->cursorTexture;
    //    cursor.setTexture(cursorTexture);
    //    cursor.setPosition(50,backText.getPosition().y+5);
    //    cursor.setScale(0.42, 0.38);
    //    cursorXpos = cursor.getPosition().x;
    //    cursorYpos =cursor.getPosition().y; // text +5
}

void GameOver :: gameloop()
{
    bool flag =true;
    
    while (name->isOpen() && flag)
    {
        flag=handleEvents();
        update();
        renderScreen();
    }
}

void GameOver:: renderScreen()
{
    this->name->clear();
    
    // pictures
    name->draw(backImage);
    
    //Text
    name->draw(title);
    name->draw(backText);
    //cursor
    //    name->draw(cursor);
    this->name->display();
}

bool GameOver :: handleEvents()
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
                
                break;
                
                // case ....
                
        }
    }
    
    return flag;
}

void GameOver :: update()
{
    // animations not linked to the user
}