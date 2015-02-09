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
#include <iostream>

// needs overloading > and ==
using namespace std;

class Cell
{
public:
    Cell();// Constructor
//    Cell(Cell &); // copy constructor
    ~Cell();
    bool isHit(); 
    bool isMiss(); // Check if a cell that is hit is a miss
    void hitCell(); // attack the ship and update the boolean "hit" update miss as well
    bool hasShip();
    void setPosition (int x, int y, bool);
    pair <int, int> getPosition ();
    bool shipSunk (); // return true if the ship the cell contains is sunk
    void placeShip(Ship*);
    Ship * getShip();
    void removeShip();
    void drawC (RenderWindow *);
    
private:
    bool hit;// set to false in constructor
    bool miss; // set to false in constructor
    int xpos, ypos;
    Ship * s; // null in constructor
    
    // SFML SHIT
    sf::Sprite cellSprite;
    sf::Texture blank;
    sf::Texture shipTexture;
    sf::Texture shipHitTexture;
    sf::Texture cellHitTexture;
    
};
#endif /* defined(__battleeee__Cell__) */
