//
//  Board.cpp
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#include "Board.h"
void Board :: initializeR() // initializes the board with ships randomly placed
{
    
}
bool Board :: isFinished() // checks if all the ships are hit.
{
    return false;
}
bool Board ::isHit (int row, int col) // checks if a cell has been hit knowing the x(col) and y(row)position
{
    return true;
}
void Board :: attack ( int row, int col) // attacks a cell with the row and column.
{
    
}

void Board:: attack ( Cell *)
{
    
}// attacks a cell

Cell* Board:: getCell (int r, int c)
{
    Cell * y=NULL;
    return y;
}// retrieve a cell by its row and column

Cell* Board::upCell(Cell * p)
{
    return p;
}

Cell* Board::downCell(Cell * p)
{
    return p;
}
Cell* Board::rightCell(Cell * p)
{
    return p;
}

Cell* Board::leftCell(Cell * p)
{
    return p;
}