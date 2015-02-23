//
//  GameW.cpp
//  battleeee
//
//  Created by Ingy on 1/25/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "GameW.h"
#include <fstream>
#include "ResourcePath.hpp"
#include "GameOver.h"

GameW :: GameW (RenderWindow * w, Settings * S) : computerB(true), playerB(false), comp(S, &playerB, &computerB), play(*S, &playerB, &computerB)
{
    name= w;
    this->S=S;
    
    initialize();
   

    
    gameloop();
    
}

GameW :: ~ GameW()
{
    
}
void GameW :: initialize()
{
    playerT=true;
    
    // read settings from file / music/ theme/ difficulty
    backTexture.loadFromFile(resourcePath()+"background9.png");
    backImage.setTexture(backTexture);
    
    gridTexture.loadFromFile(resourcePath()+"board.png");
    
    oppGrid.setTexture(gridTexture);
    playerGrid.setTexture(gridTexture);
    playerGrid.setPosition(60,60);
    oppGrid.setPosition(470, 60);
    playerGrid.setScale(0.38,0.38);
    oppGrid.setScale(0.38, 0.38);
    
    options.erase(options.begin(), options.end());
    ifstream in;
    in.open(resourcePath()+"RulesE.txt");
    
    pageFont=S->overallFont;
    //pageFont.loadFromFile(Tfont);
    
    // just for now
    //playerB.initializeR();
    
    if (S->language== "English")
    {
        // open english
        
    }
    else if(S->language== "French")
    {
        
    }
    
    // Getting the text
    
    string temp;
    getline (in, temp);
    do
    {
        for(int i=0; i<temp.size(); i++)
            if(isalpha(temp[i]))
                temp[i]=toupper(temp[i]);
        
        options.push_back(Text(temp, pageFont));
        getline (in, temp);
        
    }while(temp!="END");
    
    in.close();
    
}

void GameW :: gameloop()
{
    bool flag =true;
    
    while (name->isOpen() && flag)
    {
        flag=handleEvents();
        update();
        renderScreen();
    }
}

void GameW:: renderScreen()
{
    this->name->clear();
    
    // pictures
    name->draw(backImage);
    name->draw(oppGrid);
    name->draw(playerGrid);
    
    this ->computerB.unDraw();
    this ->playerB.unDraw();
    
    this->computerB.drawB(name, true);
    this->playerB.drawB(name, false);
    
    //    cout << "PLAYER" <<endl<<endl;
    //    playerB.debug();
    //    cout << "COMPUTER" <<endl<<endl;
    //    computerB.debug();
    
    this->name->display();
}

bool GameW :: handleEvents()
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

            case Event::MouseButtonPressed:

                if(event.mouseButton.button == Mouse::Left && playerT)
                {
                    if (m.getPosition(*name).x>oppGrid.getPosition().x && m.getPosition(*name).x<oppGrid.getPosition().x+380 && m.getPosition(*name).y>oppGrid.getPosition().y && m.getPosition(*name).y<oppGrid.getPosition().y+380)
                    {
                        int rowNumber = (m.getPosition(*name).y-60)/38;
                        int colNumber = (m.getPosition(*name).x-470)/38;
                        if(!computerB.getCell(rowNumber, colNumber)->isHit()){
                            this->play.attack(rowNumber, colNumber);
                            
                            if(this->play.missed())
                                playerT=false;
                        }
                    }
                }
                
                break;
                
                // case ....
                
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
        }
    }
    
    return flag;
}

void GameW :: update()
{
    if(!playerT)
    {
        if(S->difficulty=='H')
            comp.CattackH();
        
        else if(S->difficulty=='M')
            comp.CattackM();
        
        else comp.CattackL();
        
        if(this->comp.missed())
            playerT=true;
    }
    
    if(computerB.isFinished()||playerB.isFinished())
    {
        // window gameOver
        GameOver(this->name, this->S, computerB.isFinished());
    }
    
    // animations not linked to the user
    
}