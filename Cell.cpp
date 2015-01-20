//
//  Cell.cpp
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Cell.h"
Cell :: Cell()
{
    hit = false;        xpos = 0;  ypos = 0;
    miss = false;       s = NULL;
}

Cell:: Cell(Cell & rhs)
{
    this->hit= rhs.hit;
    this->xpos = rhs.xpos;  this->ypos = rhs.xpos;
    this->miss=rhs.miss; this->s=rhs.s; 
    
}// copy constructor

Cell :: ~Cell()
{
    
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
        miss=true;
}
bool Cell :: hasShip()
{
    return (s!=NULL);
}
void Cell :: setPosition (int x, int y)
{
    xpos = x;
    ypos = y;
}
pair<int, int> Cell :: getPosition ()
{
    return pair <int, int> (xpos,ypos);
}
bool Cell :: shipSunk () // return true if the ship the cell contains is sunk
{
    return(s->shipSunk());
}

void Cell::placeShip(Ship * p)
{
    if(s==NULL)
        this->s=p;
    else cout<< "ALREADY HAS SHIP" <<endl;
}

Ship* Cell::getShip()
{
    return s;
}

void Cell:: removeShip()
{
    s=NULL;
}