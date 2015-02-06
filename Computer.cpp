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
    previous=false;
    
    if(s->difficulty=='H')
    {
        this->initializeH();
    }

    comp->initializeR();
    
    enemy.setAvatarRE();
    
    v = new vector<Cell*>;
    h = new vector<Cell*>;
    // get a random avatar and put it to enemy
    
}

Computer::~Computer()
{
    
}

// initializing for lower levels is random
void Computer::initializeH()
{
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
    one=rand()%2;
    
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
                    
                } while (count<mode[0].size() && playerB->isHit(mode [0][count].first, mode[0][count].second)); // If this cell was not hit before
                
                if(count < mode[0].size())
                {
                    playerB->attack(mode [0][count].first, mode[0][count].second); //attack the cell
                    
                    cell = playerB->getCell(mode [0][count].first, mode[0][count].second); // get the updated cell
                    previous=cell->isMiss();
                }
                else
                {
                    one=false;
                    count = -1;
                }
                
            }
            
            if(!one) // second checkerboard pattern
            {
                do
                {
                    count ++;
                    
                } while (count<mode[1].size() && playerB->isHit(mode [1][count].first, mode[1][count].second)); // If this cell was not hit before
                
                if(count < mode[1].size())
                {
                    playerB->attack(mode [1][count].first, mode[1][count].second); //attack the cell
                    
                    cell = playerB->getCell(mode [1][count].first, mode[1][count].second); // get the updated cell
                    
                    previous=cell->isMiss();
                }
                else
                {
                    one=true;
                    count = -1;
                    CattackH();
                    return;
                }
            }
            
            if(!cell->isMiss())
            {
                if(!cell->shipSunk()) // if the ship hunted is sunk reinitialize the h options array and v options array
                {
                    hunt =true;
                    
                    h->resize(0);
                    v->resize(0);
                    
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
                
                previous=cell->isMiss();
                
                // delete the Cell that has been hit
                h->erase(h->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        v->resize(0);
                
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
                
                previous=cell->isMiss();
                
                // delete the Cell that has been hit
                v->erase(v->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        h->resize(0);
                        
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
            
            previous=cell->isMiss();
            
            if(!cell->isMiss())
            {
                if(!cell->shipSunk()) // if the ship hunted is sunk reinitialize the h optioins array and v options array
                {
                    hunt =true;
                    
                    h->resize(0);
                    v->resize(0);

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
                
                previous=cell->isMiss();
                
                // delete the Cell that has been hit
                h->erase(h->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        v->resize(0);
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
                
                previous=cell->isMiss();
                
                // delete the Cell that has been hit
                v->erase(v->begin() + cellIndex);
                
                if(!cell->shipSunk()) // if the ship searched for is not sunk -> HUNT
                {
                    if(!cell->isMiss()) // if the last attack is a miss we dont change anything
                    {
                        h->resize(0);
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
        previous= playerB->getCell(r,c)->isMiss(); // update previous
    }
}

// to check if he won
bool Computer::won()
{
    return(this->playerB->isFinished());
}

// to check if he missed last one
bool Computer::missed()
{
    return(previous);
}

