//
//  Player.h
//  battleeee
//
//  Created by Alia Hassan  on 1/7/15.
//  Copyright (c) 2015 Alia Hassan . All rights reserved.
//

#ifndef __battleeee__Player__
#define __battleeee__Player__

#include <stdio.h>


#include "Settings.h"
#include "Board.h"
#include "User.h"
#include "Cell.h"


class Player
{
public:
    Player(Settings , Board *, Board *);
    
    ~Player();
    
    //the attack function recieves the coordinates and gets the cell pointer and attacks it on the opponent board
    void attack(int , int);
    
    // to check if he won
    bool won();
    
private:
    Board * opponentB;
    Board * ownB;
    User opponent;
    
    
    
};

#endif /* defined(__battleeee__Player__) */
