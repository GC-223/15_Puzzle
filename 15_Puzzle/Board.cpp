//
//  Board.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/9/23.
//

#include "Board.hpp"

constexpr int g_lines { 25 } ;

std::ostream& operator<<( std::ostream& out, const Board& b )
{
    // while loop to print a ton of lines
    int lines { 0 } ;
    while ( lines < g_lines )
    {
        out << '\n' ;
        ++lines ;
    }
    
    // ok so we loop through the board and output the tile at row col
    for ( int row = 0 ; row < b.SIZE ; ++row )
    {
        for ( int col = 0 ; col < b.SIZE ; ++col )
        {
            out << b.m_board[ row ] [ col ] ;
        }
        
        out << '\n' ;
    }
    
    return out ;
}
