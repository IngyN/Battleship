//
//  Ship.cpp
//  battleeee
//
//  Created by Ingy on 12/30/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Ship.h"

Ship ::Ship()
{
    size = 1;
    numberHits=0;
    
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
}

Ship ::Ship(int size)
{
    this->size = size;
    numberHits=0;
    
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
}

Ship ::~Ship()
{
}

bool Ship :: shipSunk()
{
    return (numberHits == size);
}

// Setters

void Ship :: setSize(int sizeN)
{
    this->size=sizeN;
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
    
}

void Ship::setOrientation (bool horiz)
{
    if(horiz)
    {
        bottom.first=top.first;
        bottom.second=top.second+size-1;
    }
    else
    {
        bottom.first=top.first+size-1;
        bottom.second=top.second;
    }
    
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