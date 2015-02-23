//
//  Ship.cpp
//  battleeee
//
//  Created by Ingy on 12/30/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Ship.h"
#include "ResourcePath.hpp"
#include "Globals.h"

Ship ::Ship()
{
    size = 1;
    numberHits=0;
    drawn = false;
    sunk = false;
    horizontal=rand()%2;
    
    if(horizontal)
    {
        top.first=0;
        top.second =0;
        bottom.first=top.first;
        bottom.second=top.second+size-1;
    }
    else
    {
        top.first=0;
        top.second =0;
        bottom.first=top.first+size-1;
        bottom.second=top.second;
    }
    
    textures[0].loadFromFile (resourcePath()+"submarine.png");
    textures[1].loadFromFile (resourcePath()+"destroyer.png");
    textures[2].loadFromFile (resourcePath()+"cruiser.png");
    textures[3].loadFromFile (resourcePath()+"battleship.png");
    
}

Ship :: Ship (Ship& rhs)
{
    this->size=rhs.size;
    this->sunk=rhs.sunk;
    this->top=rhs.top;
    this->numberHits=rhs.numberHits;
    this->horizontal=rhs.horizontal;
    this->bottom=rhs.bottom;
    
    drawn=false;
    textures[0].loadFromFile (resourcePath()+"submarine.png");
    textures[1].loadFromFile (resourcePath()+"destroyer.png");
    textures[2].loadFromFile (resourcePath()+"cruiser.png");
    textures[3].loadFromFile (resourcePath()+"battleship.png");
}

bool Ship::  operator = (Ship & rhs)
{
    this->size=rhs.size;
    this->sunk=rhs.sunk;
    this->top=rhs.top;
    this->numberHits=rhs.numberHits;
    this->horizontal=rhs.horizontal;
    this->bottom=rhs.bottom;
    this->drawn = rhs.drawn;
    
    return true;
}

Ship ::Ship(int size)
{
    this->size = size;
    numberHits=0;
    
    sunk = false;
    horizontal=rand()%2;
    drawn=false;
    if(horizontal)
    {
        top.first=0;
        top.second =0;
        bottom.first=top.first;
        bottom.second=top.second+size-1;
    }
    else
    {
        top.first=0;
        top.second =0;
        bottom.first=top.first+size-1;
        bottom.second=top.second;
    }
    
    
    textures[0].loadFromFile (resourcePath()+"submarine.png");
    textures[1].loadFromFile (resourcePath()+"destroyer.png");
    textures[2].loadFromFile (resourcePath()+"cruiser.png");
    textures[3].loadFromFile (resourcePath()+"battleship.png");
    
    shipSprite.setTexture(textures[size-1]);
}

Ship ::~Ship()
{
}

bool Ship :: shipSunk()
{
    return (numberHits >= size);
}

// Setters

void Ship :: setSize(int sizeN)
{
    this->size=sizeN;
    shipSprite.setTexture(textures[size-1]);
    
}

void Ship :: setPosition(int rowTop,int colTop,int rowBottom,int colBottom)
{
    top.first=rowTop;
    top.second=colTop;
    
    bottom.first=rowBottom;
    bottom.second=colBottom;
}

void Ship :: setPosition(int rowTop,int colTop)
{
    top.first=rowTop;
    top.second=colTop;
    
    if(horizontal)
    {
        bottom.first=top.first;
        bottom.second=top.second+size-1;
    }
    else
    {
        bottom.first=top.first+size-1;
        bottom.second=top.second;
    }
    
}

void Ship::setOrientation (bool horiz)
{
    this->horizontal=horiz;
}

// getters

int Ship :: getSize()
{
    return size;
}

pair <pair<int,int>,pair<int,int>> Ship ::getPosition() const
{
    return make_pair(top, bottom);
}

//Booleans

bool Ship:: isH()
{
    return horizontal;
}

void Ship::hitShip()
{
    numberHits++;
    
    if(this->shipSunk())
        sunk=true;
}

void Ship :: drawShip(RenderWindow * n, bool comp)
{
    if (!drawn)
    {
        this->drawn=true;
        
        if (comp)
        {
            shipSprite.setPosition(top.second * gridCellSize + oppGridXOffset, top.first * gridCellSize + oppGridYOffset);
            
            if(this->shipSunk())
                n->draw(shipSprite);
            
            if (!this->horizontal)
            {
                shipSprite.setOrigin(0,gridCellSize);
                shipSprite.setRotation(90);
            }
            
        }
        
        else if (!comp)
        {
            shipSprite.setPosition(top.second * gridCellSize + oppGridYOffset, top.first * gridCellSize + oppGridYOffset);
            // top.second=x,top.first =y
            if (!this->horizontal)
            {
                shipSprite.setOrigin(0,gridCellSize);
                shipSprite.setRotation(90);
            }
        }
        
        if ((comp && sunk) || !comp)
        {
            n->draw(shipSprite);
        }
    }
}

void Ship:: unDrawn()
{
    this->drawn=false;
}