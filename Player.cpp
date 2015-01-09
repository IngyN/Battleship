//
//  Player.cpp
//  battleeee
//
//  Created by Alia Hassan  on 1/7/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#include "Player.h"


Player :: Player(Settings s, Board * plB, Board * opB)
{
    opponentB = opB;
    ownB = plB;
    
}

Player :: ~Player()
{
    
}
    
    //the attack function recieves the coordinates and gets the cell pointer and attacks it on the opponent board
void Player :: attack(int r, int c)
{
    if (!opponentB->isHit(r,c))
    {
        opponentB->attack(r,c);
    }
}
    
    
    
    
