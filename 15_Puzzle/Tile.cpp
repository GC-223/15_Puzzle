//
//  Tile.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/9/23.
//

#include "Tile.hpp"

// overload output so we can print
std::ostream& operator<<( std::ostream& out, const Tile& t )
{
    
    // if the tile is blank (0) then print a blank space
    if ( t.m_tileNum == 0 )
    {
        out << '\t' ;
    }
    else
    {
        out << t.m_tileNum << '\t' ;
    }
    
    return out ;
}
