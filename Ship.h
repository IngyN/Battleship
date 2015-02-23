//
//  Ship.h
//  battleeee
//
//  Created by Ingy on 12/30/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Ship__
#define __battleeee__Ship__

#include <utility>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Ship
{
public:
    Ship();
    Ship(int size);
    Ship(Ship & rhs);
    ~Ship();
    
    bool shipSunk();
    
    // setters
    void setSize(int);
    void setPosition(int rowTop,int colTop,int rowBottom,int colBottom);
    void setPosition(int rowTop,int colTop);
    void setOrientation (bool horiz);
    
    // getters
    int getSize();
    pair <pair<int,int>,pair<int,int>> getPosition() const;
    
    // booleans
    bool isH(); //is horizontal
    bool operator = (Ship &);
    
    void hitShip();
    void drawShip(RenderWindow *, bool);
    void unDrawn ();
    
private:
    
    bool sunk;
    bool horizontal;
    int size, numberHits;
    bool drawn;
    
    // top.first = rowTop (y coordinate)
    // top.second = colTop (x coordinate)
    pair <int,int> top, bottom;
    
    // Sprites and textures
    Sprite shipSprite;
    
    Texture textures[4];
    
};

#endif /* defined(__battleeee__Ship__) */
