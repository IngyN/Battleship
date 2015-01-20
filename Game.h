//
//  Game.h
//  battleeee
//
//  Created by Ingy on 1/19/15.
//  Copyright (c) 2015 Ingy. All rights reserved.
//

#ifndef __battleeee__Game__
#define __battleeee__Game__

#include "Board.h"
#include "Computer.h"
#include "Player.h"

class Game
{
public:
    Game();
    ~Game();
    
private:

    Board playerB, computerB;
    Computer comp;
    Player play;
    
};
#endif /* defined(__battleeee__Game__) */
