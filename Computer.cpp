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
    
    // initialize vector of previous moves
    prev= new vector <Cell>;

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
    // Checkerboard pattern to find ships
}

void Computer:: CattackM()
{
    Cell cell;
    // random if a ship has been sunk
    if (!hunt)
    {
        int r=(rand()%100)/10; int c= (rand()%100)/10;
        
        if (!this->won())
        {
            do
            {
                r=(rand()%100)/10; c= (rand()%100)/10; // board size 10 * 10
                
            } while (playerB->isHit(r,c)); // If this cell was not it before
            
            playerB->attack(r, c); //attack the cell
            cell = playerB->getCell(r, c); // get the updated cell
            
            if(!cell.isMiss())
            { hunt =true; pair <int,int> position = cell.getPosition();}
            
            if(cell.shipSunk()) // if the ship hunted is sunk reinitialize the previous moves array
                prev=new vector <Cell>;
            
            else this->prev->push_back(cell); // else add this cell to the previous moves
        }
    }
    // two vectors to update h and v 
    else // if a ship hasn't been sunk yet, any cell in previous has been hit at least one hit
    {
        if(!prev->back().isMiss()) //  if the last was a hit then we search for the previous hit
        {
             vector <Cell> prevHits;
            
            for(int i=0; i<5; i++)
                if (!prev->at(prev-> size()-1-i).isMiss())
                    prevHits.push_back(prev->at(prev-> size()-1-i));
            
            if (prevHits.size()>=2) // There's another hit.
            {
                pair <int,int> position1=prevHits.back().getPosition(); // Position 1 is the most recent
                pair <int,int> position2=prevHits[prevHits.size()-2].getPosition();
                
                if (position1.first==position2.first)
                {
                    if(position1.second>position2.second)
                    {
                        playerB->attack(position1.second+1, position2.first);
                        
                        cell = playerB->getCell(position1.second+1, position2.first); // get the updated cell
                        
                        if(cell.shipSunk()) // if the ship hunted is sunk reinitialize the previous moves array
                        { prev=new vector <Cell>; hunt=false;}
                        
                        else this->prev->push_back(cell); // else add this cell to the previous moves
                    }
                    
                    else
                    {
                        playerB->attack(position1.second-1, position2.first);
                        
                        cell = playerB->getCell(position1.second-1, position2.first); // get the updated cell
                        
                        if(cell.shipSunk()) // if the ship hunted is sunk reinitialize the previous moves array
                            { prev=new vector <Cell>; hunt=false;}
                        
                        else this->prev->push_back(cell); // else add this cell to the previous moves
                    }
                }
                else // position1.second = position2.second y=y
                {
                    if(position1.first>position2.first)
                    {
                        playerB->attack(position1.second, position1.first+1);
                        
                        cell = playerB->getCell(position1.second, position1.first+1); // get the updated cell
                        
                        if(cell.shipSunk()) // if the ship hunted is sunk reinitialize the previous moves array
                            { prev=new vector <Cell>; hunt=false;}
                        
                        else this->prev->push_back(cell); // else add this cell to the previous moves
                    }
                    else // position1.first<position2.first
                    {
                            playerB->attack(position1.second, position1.first-1);
                            
                            cell = playerB->getCell(position1.second, position1.first-1); // get the updated cell
                            
                            if(cell.shipSunk()) // if the ship hunted is sunk reinitialize the previous moves array
                                { prev=new vector <Cell>; hunt=false;}
                            
                            else this->prev->push_back(cell); // else add this cell to the previous moves
                        }
                }
            }

            else // There's only one hit
            {
                
            }
            
        }
        
        else // if the last element is a miss
        {
            
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
        
        if(cell.shipSunk()) // if the ship hunted is sunk reinitialize the previous moves array
            prev=new vector <Cell>;
        
        else this->prev->push_back(cell); // else add this cell to the previous moves
    }
}

// to check if he won
bool Computer::won()
{
    return(this->playerB->isFinished());
}

