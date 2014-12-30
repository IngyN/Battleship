//
//  Computer.cpp
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Computer.h"


Computer::Computer(Settings * s, Board * player, Board * comp)
{
    if(s->difficulty=='H')
    {
        this->initializeH();
    }
    else
    {
        comp->initializeR();
    }
    
    // get a random avatar and put it to Enemy
}

Computer::~Computer()
{
    
}

// initializing for lower levels is random
void Computer::initializeH()
{

} // initializing for level hard

// Levels of attacks H for High, M for Medium, L for low
void Computer:: CattackH()
{

}

void Computer:: CattackM()
{

}
void Computer::CattackL()
{

}

// to check if he won
bool Computer::won()
{

}

