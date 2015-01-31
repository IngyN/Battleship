//
//  GameW.cpp
//  battleeee
//
//  Created by Ingy on 1/25/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#include "GameW.h"
#include <fstream>

GameW :: GameW (RenderWindow * w, Settings * S) :comp(S, &playerB, &computerB), play(*S, &playerB, &computerB)
{
    name= w;
    this->S=S;
    
    initialize();
    
    gameloop();
    playerT=true;
    
}

GameW :: ~ GameW()
{
    
}
void GameW :: initialize()
{
    // read settings from file / music/ theme/ difficulty
    backTexture.loadFromFile("/Users/Ingy/Desktop/battleeee/battleeee/data/Images/BackgroundImages/background2.png");
    backImage.setTexture(backTexture);
    
    gridTexture.loadFromFile("/Users/Ingy/Downloads/board.png");
    
    oppGrid.setTexture(gridTexture);
    playerGrid.setTexture(gridTexture);
    playerGrid.setPosition(60,60);
    oppGrid.setPosition(470, 60);
    
    shipTexture.loadFromFile("/Users/Ingy/Desktop/battleeee/battleeee/data/Images/sprites/Ships/ship1.png");
    shipHitTexture.loadFromFile("/Users/Ingy/Desktop/battleeee/battleeee/data/Images/sprites/Ships/ship2.png");
    
    for(int i=0; i<20; i++)
        shipSprite[i].setTexture(shipTexture);
    
    int count =0;
    for (int i=0; i<10; i++)
        for (int j=0; j<10;j++)
            if (computerB.hasShip(i, j))
            {
                shipSprite[count].setPosition(470+38*i, 60+38*j);
                count++;
            }
    
    
    options.erase(options.begin(), options.end());
    ifstream in;
    in.open("/Users/Ingy/Desktop/battleeee/battleeee/data/Text/Rules/RulesE.txt");
    
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
    //    //Text
    //    name->draw(title);
    //    name->draw(backText);
    //
    //    for(int i=0; i<rules.size();i++)
    //    {
    //        name->draw(rules[i]);
    //    }
    //
    //    //cursor
    //    name->draw(cursor);
    // Displaying ships
    
    for(int i=0; i<20; i++)
        name->draw(shipSprite[i]);
        
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
                
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                {
                    flag=false;
                }
                if (event.key.code == Keyboard::Return && cursor.getPosition().y == backText.getPosition().y+5)
                {
                    flag=false;
                }
            case Event::MouseButtonPressed:
                if(Mouse::isButtonPressed(Mouse::Left)&&playerT)
                {
                    if (m.getPosition().x>oppGrid.getPosition().x && m.getPosition().x<oppGrid.getPosition().x+378 && m.getPosition().y>oppGrid.getPosition().y && m.getPosition().y<oppGrid.getPosition().y+374)
                    {
                        
                        this->play.attack((m.getPosition().y-60)%38,(m.getPosition().x-470)%38);
                        
                        if(this->play.missed())
                            playerT=false;
                    }
                }
                
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
                
                break;
                
                // case ....
                
        }
    }
    
    return flag;
}

void GameW :: update()
{
    // animations not linked to the user
    int count =0;
    for (int i=0; i<10; i++)
        for (int j=0; j<10;j++)
            if (computerB.hasShip(i, j)&& computerB.isHit(i, j))
            {
                shipSprite[count].setTexture(shipHitTexture);
                count++;
            }
}