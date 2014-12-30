//
//  Computer.h
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Computer__
#define __battleeee__Computer__

#include "Settings.h"
#include "Board.h"
#include "User.h"
#include "Cell.h"


class Computer
{
public:
    Computer(Settings *, Board *, Board *);
    ~Computer();
    
    // initializing for lower levels is random
    void initializeH(); // initializing for level hard
    
    // Levels of attacks H for High, M for Medium, L for low
    void CattackH();
    void CattackM();
    void CattackL();
    
private:
    User enemy;
    int nbOfShips;
    vector <Cell> prev; // stores previous moves
};

#endif /* defined(__battleeee__Computer__) */
