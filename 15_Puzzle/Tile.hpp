//
//  Tile.hpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/9/23.
//

#ifndef Tile_hpp
#define Tile_hpp

#include <iostream>

// tile class
class Tile
{
private:
    // hold the number of the tile
    int m_tileNum { } ;
    
public:
    // default constructor
    Tile() = default ;
    
    // explicit constructor to create tiles
    Tile( int tileNum ) : m_tileNum( tileNum ) { }
    
    // overload output operator so we can print tileNum
    friend std::ostream& operator<<( std::ostream& out, const Tile& t ) ;
    
    // check if tile is empty
    // return true if empty
    bool isEmpty() { return m_tileNum == 0 ; }
    
    // getters
    int getTileNum() { return m_tileNum ; }
    
} ;




#endif /* Tile_hpp */
