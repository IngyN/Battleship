//
//  Board.h
//  battleeee
//
//  Created by Ingy on 12/29/14.
//  Copyright (c) 2014 Ingy. All rights reserved.
//

#ifndef __battleeee__Board__
#define __battleeee__Board__

#include "Cell.h"
#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

class Board
{
public:
    
    Board(); // Constructor
    ~Board(); // Destructor
    void initializeR(); // initializes the board with ships randomly placed
    bool isFinished(); // checks if all the ships are hit.
    bool isHit (int row, int col); // checks if a cell has been hit knowing the x(col) and y(row) position
    void attack ( int row, int col); // attacks a cell with the row and column.
    void attack ( Cell *); // attacks a cell
    Cell* getCell (int r, int c); // retrieve a cell by its row and column
    void placeShip(int row, int col, int num); // place a ship fron the deck on the board
    
    // to get surrounding Cells within the boundaries
    Cell* upCell(Cell *);
    Cell* downCell(Cell *);
    Cell* rightCell(Cell *);
    Cell* leftCell(Cell *);
private:
    Cell B[10][10];  // 2D array
    Ship SH[10]; // ships belonging to the board
};

#endif /* defined(__battleeee__Board__) */
