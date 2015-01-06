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
    enemyB=comp;
    playerB=player;
    hunt = false;
    
    if(s->difficulty=='H')
    {
        this->initializeH();
    }
    else
    {
        comp->initializeR();
    }
    
    enemy.setAvatarRE();
    // get a random avatar and put it to enemy
    
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
    // Checkerboard pattern to find ships and Hunt mode
}

void Computer:: CattackM() // random if a ship has been sunk, Hunt mode if a hit is achieved
{
    Cell cell;
    
    if (!this->won())
    {
        if (!hunt)
        {
            int r=(rand()%100)/10; int c= (rand()%100)/10;
            
            do
            {
                r=(rand()%100)/10; c= (rand()%100)/10; // board size 10 * 10
                
            } while (playerB->isHit(r,c)); // If this cell was not it before
            
            playerB->attack(r, c); //attack the cell
            cell = playerB->getCell(r, c); // get the updated cell
            
            if(!cell.isMiss())
            {
                hunt =true;
                
                if(cell.shipSunk()) // if the ship hunted is sunk reinitialize the h optioins array and v options array
                {
                    h=new vector <Cell>;
                    v=new vector<Cell>;
                    
                    // Updating h and v with the possible options for attack
                    if(!playerB->downCell(cell).isHit())
                        v->push_back(playerB->downCell(cell));
                    
                    if(!playerB->upCell(cell).isHit())
                        v->push_back(playerB->upCell(cell));
                    
                    if(!playerB->rightCell(cell).isHit())
                        h->push_back(playerB->rightCell(cell));
                    
                    if(!playerB->leftCell(cell).isHit())
                        h->push_back(playerB->leftCell(cell));
                }
            }
        }
        
        
        // NOTE: if the attack is a hit then the computer must continue... Recall function?
        
        // two vectors to update h and v
        
        else // if a ship hasn't been sunk yet, any cell in previous has been hit at least one hit
        {
            // if the size of one of the vectors h or v is equal to 0 then the ship is in the other direction
            if(h->size()!=0)
            {
                playerB->attack(h->back()); // attack cell
                
                // get updated Cell
                Cell cell=playerB->getCell(h->back().getPosition().second,h->back().getPosition().first);
                
                h->pop_back(); // delete the Cell that has been hit
                
                if(!cell.shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell.isMiss()) // if the last attack is a miss we dont change anything
                    {
                        if(v->size()!=0) // if there is a possibility that the ship hunted is vertical, then update vertical options
                        {
                            if(!playerB->upCell(cell).isHit())
                                v->push_back(playerB->upCell(cell));
                            
                            if(!playerB->downCell(cell).isHit())
                                v->push_back(playerB->downCell(cell));
                        }
                        
                        // add the rightCell and leftCell if they are options
                        if(!playerB->rightCell(cell).isHit())
                            h->push_back(playerB->rightCell(cell));
                        
                        if(!playerB->leftCell(cell).isHit())
                            h->push_back(playerB->leftCell(cell));
                    }
                    
                }
                
                else // if the ship is sunk stop hunting
                {
                    hunt=false;
                }
                
                // If the computer got a hit he continues
                if(!cell.isMiss())
                    this->CattackM();
                
            }
            else if(v->size()!=0) // we put else if to explore horizontal options first then vertical options because every time the function is called it must attack only once.
            {
                v->back().hitCell();
                
                // get updated Cell
                Cell cell=playerB->getCell(v->back().getPosition().second,v->back().getPosition().first);
                
                v->pop_back(); // delete the Cell that has been hit
                
                if(!cell.shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell.isMiss()) // if the last attack is a miss we dont change anything
                    {
                        if(h->size()!=0) // if there is a possibility that the ship hunted is horizontal, then update horizontal options
                        {
                            if(!playerB->rightCell(cell).isHit())
                                h->push_back(playerB->rightCell(cell));
                            
                            if(!playerB->leftCell(cell).isHit())
                                h->push_back(playerB->leftCell(cell));
                        }
                        
                        // add the upCell and downCell if they are options
                        if(!playerB->upCell(cell).isHit())
                            v->push_back(playerB->upCell(cell));
                        
                        if(!playerB->downCell(cell).isHit())
                            v->push_back(playerB->downCell(cell));
                        
                    }
                    
                }
                
                else // if the ship is sunk stop hunting
                {
                    hunt=false;
                }
                
                // If the computer got a hit he continues
                if(!cell.isMiss())
                    this->CattackM();
            }
        }
        
    }
}

void Computer::CattackL()
{
    int r=(rand()%100)/10; int c= (rand()%100)/10;
    
    if (!this->won())
    {
        do
        {
            r=(rand()%100)/10; c= (rand()%100)/10; // board size 10 * 10
            
        }while (playerB->isHit(r,c)); // If this cell was not it before
        
        playerB->attack(r, c); //attack the cell
        Cell cell = playerB->getCell(r, c);
        
        // If the computer got a hit he continues
        if(!cell.isMiss()) // if the ship hunted is sunk reinitialize the previous moves array
            this->CattackL();
    }
}

// to check if he won
bool Computer::won()
{
    return(this->playerB->isFinished());
}

