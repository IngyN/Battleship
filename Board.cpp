//
//  Board.cpp
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Board.h"

Board::Board() // Constructor
{
    SH[0].setSize(4);// Battleship
    
    SH[1].setSize(3);// Cruiser
    SH[2].setSize(3);// Cruiser
    
    SH[3].setSize(2);// Destroyer
    SH[4].setSize(2);// Destroyer
    SH[5].setSize(2);// Destroyer
    
    for (int i=6; i<10;i++)
        SH[i].setSize(1);// Submarine
    
    bool comp=true;
    
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            this->B[i][j].setPosition(j, i, comp);
    
}

Board::Board(bool comp) // Constructor
{
    
    SH[0].setSize(4);// Battleship
    
    
    SH[1].setSize(3);// Cruiser
    SH[2].setSize(3);// Cruiser
    
    SH[3].setSize(2);// Destroyer
    SH[4].setSize(2);// Destroyer
    SH[5].setSize(2);// Destroyer
    
    for (int i=6; i<10;i++)
        SH[i].setSize(1);// Submarine
    
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            this->B[i][j].setPosition(j, i, comp);
    
}

Board::~Board() // Destructor
{
}

bool Board :: placeShip(int row, int col, int num)
{
    Ship * p;
    p= & SH[num];
    
    bool valid = true;
    
    if (p->isH())
    {
        for(int i=-1; i<2; i++)
            for(int j=-1; j<SH[num].getSize()+1; j++)
            {
                if(row+i >= 0 && row+i < 10 && col+j >= 0 && col+j < 10)
                {
                    if(B[row+i][col+j].hasShip())
                        valid=false;
                }
                else
                {
                    //valid= false;
                }
            }
    }
    else
        for(int i=-1; i<SH[num].getSize()+1; i++)
            for(int j=-1; j<2; j++)
            {
                if(row+i >= 0 && row+i < 10 && col+j >= 0 && col+j < 10)
                {
                    if(B[row+i][col+j].hasShip())
                        valid=false;
                }
                else
                {
                    //valid = false;
                }
            }
    
    if(valid)
    {
        if(p->isH())
            for (int i=0; i<SH[num].getSize();i++)
            {
                p->setPosition(row, col);
                B[row][col+i].placeShip(p);
            }
        else
            for (int i=0; i<SH[num].getSize();i++)
            {
                p->setPosition(row, col);
                B[row+i][col].placeShip(p);
            }
        
        p->setPosition(row, col);
    }
    
    else cout << "CANNOT PLACE SHIP";
    return valid;
}

bool Board::changePos(int row, int col, int toRow, int toCol)
{
    Ship * p= this->getShip(row, col);
    
    bool valid=true;
    
    if(p->isH())
    {
        for(int i=-1; i<2; i++)
            for(int j=-1; j<p->getSize()+1; j++)
                if(B[toRow+i][toCol+j].hasShip())
                    valid=false;
    }
    else
        for(int i=-1; i<p->getSize()+1; i++)
            for(int j=-1; j<2; j++)
                if(B[toRow+i][toCol+j].hasShip())
                    valid=false;
    
    if(!B[toRow][toCol].hasShip())
    {
        B[row][col].removeShip();
        B[toRow][toCol].placeShip(p);
    }
    
    return valid;
    
}// change the position of a ship from row, col to toRow, toCol

void Board :: initializeR() // initializes the board with ships randomly placed
{
    int r,c;
    
    bool valid; bool h;
    
    for(int w=0; w<10; w++)
    {
        do
        {
            valid =true;
            
            h= rand()%2;
            
            if (h)
            {
                r =rand ()%(10);
                c =rand()%(10-SH[w].getSize()+1);
            }
            else
            {
                r =rand ()%(10-SH[w].getSize()+1);
                c =rand()%(10);
            }
            
            SH[w].setOrientation(h);
            
            valid=placeShip(r, c, w);
            
        } while (!valid);
        
        
        SH[w].setPosition(r, c);
        
    }
    
}

bool Board :: isFinished() // checks if all the ships are hit.
{
    bool f=true;
    
    int i=0;
    while(f && i<10)
    {
        for(int j=0; j<10; j++)
            if(B[i][j].hasShip() && !B[i][j].shipSunk())
                f=false;
        i++;
    }
    return f;
}

bool Board ::isHit (int row, int col) // checks if a cell has been hit knowing the x(col) and y(row)position
{
    return B[row][col].isHit();
}

bool Board ::hasShip (int row, int col) // checks if a cell has been hit knowing the x(col) and y(row)position
{
    return B[row][col].hasShip();
}

void Board :: attack (int row, int col) // attacks a cell with the row and column.
{
    B[row][col].hitCell();
    
    if(B[row][col].shipSunk())
    {
        Ship * ship;
        ship=B[row][col].getShip();
        
        row = (ship->getPosition()).first.first;
        col = (ship->getPosition()).first.second;
        
        if (ship->isH())
        {
            for (int i=-1; i<2; i++)
                for (int j=-1; j<ship->getSize()+1; j++)
                    if(withinBoundaries( row + i, col + j))
                        //if(!B[row+i][col+j].isHit())
                        B[row+i][col+j].hitCell();
        }
        else
        {
            for (int i=-1; i<ship->getSize()+1; i++)
                for (int j=-1; j<2; j++)
                    if(withinBoundaries(row + i, col + j))
                        //if(!B[row+i][col+j].isHit())
                        B[row+i][col+j].hitCell();
        }
    }
}

bool Board :: withinBoundaries(int i, int j)
{
    return(i>=0 && i<=9 && j>=0 && j<= 9);
}

void Board:: attack (Cell * p)
{
    B[p->getPosition().second][p->getPosition().first].hitCell();
    
    if(B[p->getPosition().second][p->getPosition().first].shipSunk())
    {
        Ship * ship;
        ship=B[p->getPosition().second][p->getPosition().first].getShip();
        
        int row = (ship->getPosition()).first.first;
        int col = (ship->getPosition()).first.second;
        
        if (ship->isH())
        {
            for (int i=-1; i<2; i++)
                for (int j=-1; j<ship->getSize()+1; j++)
                    if(withinBoundaries( row + i, col + j))
                        //if(!B[row+i][col+j].isHit())
                        B[row+i][col+j].hitCell();
        }
        else
        {
            for (int i=-1; i<ship->getSize()+1; i++)
                for (int j=-1; j<2; j++)
                    if(withinBoundaries(row + i, col + j))
                        //if(!B[row+i][col+j].isHit())
                        B[row+i][col+j].hitCell();
        }
    }
    
}// attacks a cell

Cell* Board:: getCell (int r, int c)
{
    Cell * y;
    y=&B[r][c];
    return y;
    
}// retrieve a cell by its row and column

Ship* Board:: getShip (int r, int c)
{
    Ship * y;
    y=B[r][c].getShip();
    return y;
    
}// retrieve a ship by its row and column

Cell* Board::upCell(Cell * p)
{
    if(p->getPosition().second-1 >= 0){
        Cell * n = p;
        n = &B[p->getPosition().second-1][p->getPosition().first];
        return n;
    }
    else
        return NULL;
}

Cell* Board::downCell(Cell * p)
{
    if(p->getPosition().second +1 < 10)
    {
        Cell * n = p;
        n = &B[p->getPosition().second +1][p->getPosition().first];
        return n;
    }
    else
        return NULL;
}

Cell* Board::rightCell(Cell * p)
{
    if(p->getPosition().first+1 < 10)
    {
        Cell * n = p;
        n = & B[p->getPosition().second][p->getPosition().first+1];
        return n;
    }
    else
        return NULL;
}

Cell* Board::leftCell(Cell * p)
{
    if(p->getPosition().first-1 >= 0)
    {
        Cell * n = p;
        n = & B[p->getPosition().second][p->getPosition().first-1];
        return n;
    }
    else
        return NULL;
}

void Board:: drawB(RenderWindow * n, bool comp)
{
    for (int i=0; i<10; i++)
        SH[i].drawShip(n, comp);
    
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
            if(B[i][j].isHit())B[i][j].drawC(n);
    
}

void Board :: unDraw()
{
    for (int i=0; i<10; i++)
        SH[i].unDrawn();
}

void Board:: debug()
{
    cout <<"--------------------------------------------------"<<endl;
    
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++)
        {
            if(B[i][j].hasShip())
                cout << 'X';
            else cout << '$';
        }
        cout <<endl;
    }
    
    cout <<"--------------------------------------------------"<<endl;
}