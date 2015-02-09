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
    ownB->initializeR();
}

Player :: ~Player()
{
    
}

//the attack function receives the coordinates and gets the cell pointer and attacks it on the opponent board
void Player :: attack(int r, int c)
{
    if(!opponentB->isFinished())
    {
        if (!opponentB->isHit(r,c))
        {
            opponentB->attack(r,c);
            previous=opponentB->getCell(r, c)->isMiss();
        }
    }
}

bool Player::won()
{
    return ownB->isFinished();
}


bool Player::missed()
{
    return previous;
}