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
    
    // checkerboard pattern
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            mode[(i+j)%2].push_back(make_pair(i,j));
    
    int r;
    // shuffling the modes
    for(int j=0; j<2; j++)
        for (int i=mode[j].size()-1; i>0; i--)
        {
            r= rand()%(i+1);
            swap(mode[j][r],mode[j][i]);
        }
    
    count =-1;
    one=true;
    
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
    Cell * cell;
    
    if (!this->won())
    {
        if (!hunt)
        {
            
            if (one) // first checkerboard pattern
            {
                do
                {
                    count ++;
                    
                } while (playerB->isHit(mode [0][count].first, mode[0][count].second) && count<mode[0].size()-1); // If this cell was not hit before
                
                playerB->attack(mode [0][count].first, mode[0][count].second); //attack the cell
                
                cell = playerB->getCell(mode [0][count].first, mode[0][count].second); // get the updated cell
                
                if(count>=mode[0].size())
                    one=false;
                
            }
            else // second checkerboard pattern (the remaining cells)
            {
                do
                {
                    count --;
                    
                } while (playerB->isHit(mode [1][count].first, mode[1][count].second) && count>0); // If this cell was not hit before
                
                playerB->attack(mode [1][count].first, mode[1][count].second); //attack the cell
                
                cell = playerB->getCell(mode [1][count].first, mode[1][count].second); // get the updated cell
            }
            
            if(!cell->isMiss())
            {
                
                
                if(!cell->shipSunk()) // if the ship hunted is sunk reinitialize the h options array and v options array
                {
                    hunt =true;
                    h->clear();
                    v->clear();
                    // Updating h and v with the possible options for attack
                    if(playerB->downCell(cell) != NULL && !playerB->downCell(cell)->isHit())
                        v->push_back(playerB->downCell(cell));
                    
                    if(playerB->upCell(cell) != NULL && !playerB->upCell(cell)->isHit())
                        v->push_back(playerB->upCell(cell));
                    
                    if(playerB->rightCell(cell) != NULL && !playerB->rightCell(cell)->isHit())
                        h->push_back(playerB->rightCell(cell));
                    
                    if(playerB->leftCell(cell) != NULL && !playerB->leftCell(cell)->isHit())
                        h->push_back(playerB->leftCell(cell));
                }
            }
        }
        
        
        // NOTE: if the attack is a hit then the computer must continue... Recall function?
        
        // two vectors to update h and v
        
        else // if a ship hasn't been sunk yet, any cell in previous has been hit at least one hit
        {
            bool hitHorizontal = true;
            if (h->size()>0 && v->size()>0)
            {
                hitHorizontal = rand()%2;
            }
            else
            {
                hitHorizontal = (h->size()!=0);
            }
            // if the size of one of the vectors h or v is equal to 0 then the ship is in the other direction
            if(hitHorizontal)
            {
                int cellIndex = rand() % h->size();
                playerB->attack((*h)[cellIndex]); // attack cell
                
                // get updated Cell
                Cell  * cell=playerB->getCell((*h)[cellIndex]->getPosition().second,(*h)[cellIndex]->getPosition().first);
                
                /*h->pop_back();*/ // delete the Cell that has been hit
                h->erase(h->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        v->clear();
                        // add the rightCell and leftCell if they are options
                        if(playerB->rightCell(cell) != NULL && !playerB->rightCell(cell)->isHit())
                            h->push_back(playerB->rightCell(cell));
                        
                        if(playerB->leftCell(cell) != NULL && !playerB->leftCell(cell)->isHit())
                            h->push_back(playerB->leftCell(cell));
                    }
                    
                }
                
                else // if the ship is sunk stop hunting
                {
                    hunt=false;
                }
                
            }
            else // we put else if to explore horizontal options first then vertical options because every time the function is called it must attack only once.
            {
                int cellIndex = rand() % v->size();
                playerB->attack((*v)[cellIndex]); // attack cell
                
                // get updated Cell
                Cell  * cell=playerB->getCell((*v)[cellIndex]->getPosition().second,(*v)[cellIndex]->getPosition().first);
                
                /*h->pop_back();*/ // delete the Cell that has been hit
                v->erase(v->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        h->clear();
                        // add the upCell and downCell if they are options
                        if(playerB->downCell(cell) != NULL && !playerB->downCell(cell)->isHit())
                            v->push_back(playerB->downCell(cell));
                        
                        if(playerB->upCell(cell) != NULL && !playerB->upCell(cell)->isHit())
                            v->push_back(playerB->upCell(cell));
                    }
                    
                }
                
                else // if the ship is sunk stop hunting
                {
                    hunt=false;
                }
            }
        }
        
    }
    
}

void Computer:: CattackM() // random if a ship has been sunk, Hunt mode if a hit is achieved
{
    Cell * cell;
    
    if (!this->won())
    {
        if (!hunt)
        {
            int r, c;
            
            do
            {
                r = rand()%10;
                c = rand()%10; // board size 10 * 10
                
            } while (playerB->isHit(r,c)); // If this cell was not it before
            
            playerB->attack(r, c); //attack the cell
            cell = playerB->getCell(r, c); // get the updated cell
            
            if(!cell->isMiss())
            {
                
                
                if(!cell->shipSunk()) // if the ship hunted is sunk reinitialize the h optioins array and v options array
                {
                    hunt =true;
                    h->clear();
                    v->clear();
                    // Updating h and v with the possible options for attack
                    if(playerB->downCell(cell) != NULL && !playerB->downCell(cell)->isHit())
                        v->push_back(playerB->downCell(cell));
                    
                    if(playerB->upCell(cell) != NULL && !playerB->upCell(cell)->isHit())
                        v->push_back(playerB->upCell(cell));
                    
                    if(playerB->rightCell(cell) != NULL && !playerB->rightCell(cell)->isHit())
                        h->push_back(playerB->rightCell(cell));
                    
                    if(playerB->leftCell(cell) != NULL && !playerB->leftCell(cell)->isHit())
                        h->push_back(playerB->leftCell(cell));
                }
            }
        }
        
        
        // NOTE: if the attack is a hit then the computer must continue... Recall function?
        
        // two vectors to update h and v
        
        else // if a ship hasn't been sunk yet, any cell in previous has been hit at least one hit
        {
            bool hitHorizontal = true;
            if (h->size()>0 && v->size()>0)
            {
                hitHorizontal = rand()%2;
            }
            else
            {
                hitHorizontal = (h->size()!=0);
            }
            // if the size of one of the vectors h or v is equal to 0 then the ship is in the other direction
            if(hitHorizontal)
            {
                int cellIndex = rand() % h->size();
                playerB->attack((*h)[cellIndex]); // attack cell
                
                // get updated Cell
                Cell  * cell=playerB->getCell((*h)[cellIndex]->getPosition().second,(*h)[cellIndex]->getPosition().first);
                
                /*h->pop_back();*/ // delete the Cell that has been hit
                h->erase(h->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        v->clear();
                        // add the rightCell and leftCell if they are options
                        if(playerB->rightCell(cell) != NULL && !playerB->rightCell(cell)->isHit())
                            h->push_back(playerB->rightCell(cell));
                        
                        if(playerB->leftCell(cell) != NULL && !playerB->leftCell(cell)->isHit())
                            h->push_back(playerB->leftCell(cell));
                    }
                    
                }
                
                else // if the ship is sunk stop hunting
                {
                    hunt=false;
                }
                
            }
            else // we put else if to explore horizontal options first then vertical options because every time the function is called it must attack only once.
            {
                int cellIndex = rand() % v->size();
                playerB->attack((*v)[cellIndex]); // attack cell
                
                // get updated Cell
                Cell  * cell=playerB->getCell((*v)[cellIndex]->getPosition().second,(*v)[cellIndex]->getPosition().first);
                
                /*h->pop_back();*/ // delete the Cell that has been hit
                v->erase(v->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        h->clear();
                        // add the upCell and downCell if they are options
                        if(playerB->downCell(cell) != NULL && !playerB->downCell(cell)->isHit())
                            v->push_back(playerB->downCell(cell));
                        
                        if(playerB->upCell(cell) != NULL && !playerB->upCell(cell)->isHit())
                            v->push_back(playerB->upCell(cell));
                    }
                    
                }
                
                else // if the ship is sunk stop hunting
                {
                    hunt=false;
                }
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
    }
}

// to check if he won
bool Computer::won()
{
    return(this->playerB->isFinished());
}

