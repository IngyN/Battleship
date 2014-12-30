//
//  Cell.h
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Cell__
#define __battleeee__Cell__

#include <Ship.h>

class Cell
{
public:
    bool isHit();
    void hitCell();
    bool hasShip();
    void setPosition (int x, int y);
private:
    bool hit;
    int xpos, ypos;
    Ship * s;
    
    
};
#endif /* defined(__battleeee__Cell__) */
