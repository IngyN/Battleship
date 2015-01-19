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
    
    SH[6].setSize(1);// Submarine
}

Board::~Board() // Destructor
{
}

void Board :: placeShip(int row, int col, int num)
{
    Ship * p = nullptr;
    *p= SH[num];
    
    B[row][col].placeShip(p);
}

void Board :: initializeR() // initializes the board with ships randomly placed
{
    
}
bool Board :: isFinished() // checks if all the ships are hit.
{
    bool f=true;
    
    int i=0;
    while(f && i<10)
    {
        for(int j=0; j<10; j++)
            if(!B[i][j].shipSunk())
                f=false;
        i++;
    }
    return f;
}
bool Board ::isHit (int row, int col) // checks if a cell has been hit knowing the x(col) and y(row)position
{
    return B[row][col].isHit();
}
void Board :: attack ( int row, int col) // attacks a cell with the row and column.
{
    B[row][col].hitCell();
}

void Board:: attack (Cell * p)
{
    B[p->getPosition().second][p->getPosition().first].hitCell();
    
}// attacks a cell

Cell* Board:: getCell (int r, int c)
{
    Cell * y=new Cell;
    *y=B[r][c];
    return y;
    
}// retrieve a cell by its row and column

Cell* Board::upCell(Cell * p)
{
    Cell * n = p;
    * n = B[p->getPosition().second-1][p->getPosition().first];
    return n;
}

Cell* Board::downCell(Cell * p)
{
    Cell * n = p;
    * n = B[p->getPosition().second +1][p->getPosition().first];
    return n;
}
Cell* Board::rightCell(Cell * p)
{
    Cell * n = p;
    * n = B[p->getPosition().second][p->getPosition().first+1];
    return n;
}

Cell* Board::leftCell(Cell * p)
{
    Cell * n = p;
    * n = B[p->getPosition().second][p->getPosition().first-1];
    return n;
}