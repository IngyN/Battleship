//
//  Cell.cpp
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Cell.h"
#include "Globals.h"
#include "ResourcePath.hpp"
#include <iostream>

using namespace std;

Cell :: Cell()
{
    hit = false;        xpos = 0;  ypos = 0;
    miss = false;       s = NULL;
    
    cellSprite.setTexture(blank);
    
    string textureSource= resourcePath()+ "ship1.png";
    
    this->shipTexture.loadFromFile(textureSource);
    
    string textureSource1= resourcePath()+ "ship2.png";
    
    this->shipHitTexture.loadFromFile(textureSource1);
    
    string textureSource2=resourcePath()+ "cross.png";
    
    this-> cellHitTexture.loadFromFile(textureSource2);
}

Cell :: ~Cell()
{
    
}

void Cell :: drawC (RenderWindow * n)
{
    n->draw(cellSprite);
}

bool Cell :: isHit()
{
    return hit;
}
bool Cell :: isMiss() // Check if a cell that is hit is a miss
{
    return miss;
}
void Cell :: hitCell() // attack the ship and update the boolean "hit" update miss as well
{
    hit = true;
    
    if(!this->hasShip())
    {
        miss=true;
        cellSprite.setTexture(cellHitTexture);
        cellSprite.setTextureRect(IntRect(0,0,cellHitTexture.getSize().x, cellHitTexture.getSize().y));
    }
    
    else
    {
       cellSprite.setTexture(shipHitTexture);
        s->hitShip();
    }
}
bool Cell :: hasShip()
{
    return (s!=NULL);
}

void Cell :: setPosition (int x, int y, bool comp)
{
    xpos = x;
    ypos = y;
    
    if(comp)
        cellSprite.setPosition(oppGridXOffset+xpos*gridCellSize, oppGridYOffset+ypos*gridCellSize);
    else cellSprite.setPosition(plGridXOffset+xpos*gridCellSize, plGridYOffset+ypos*gridCellSize);
}
pair<int, int> Cell :: getPosition ()
{
    return pair <int, int> (xpos,ypos);
}
bool Cell :: shipSunk () // return true if the ship the cell contains is sunk
{
    if(s != NULL)
        return(s->shipSunk());
    else{
      //  cout << "error s is null!!!" << endl;
        return false;
    }
}

void Cell::placeShip(Ship * p)
{
    if(s==NULL)
    {
        this->s=p;
        cellSprite.setTexture(shipTexture);
        cellSprite.setTextureRect(IntRect(0,0,shipTexture.getSize().x, shipTexture.getSize().y));
    }
    else cout<< "ALREADY HAS SHIP" <<endl;
}

Ship* Cell::getShip()
{
    return s;
}

void Cell:: removeShip()
{
    s=NULL;
    cellSprite.setTexture(blank);
}