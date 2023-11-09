//
//  main.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/8/23.
//

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



int main(int argc, const char * argv[]) 
{
    
    Tile t1 { 5 } ;
    Tile t2 { 12 } ;
    Tile t3 { 0 } ;
    Tile t4 { 1 } ;
    
    std::cout << t1 << t2 << t3 << t4 << '\n' ;
    
    return 0;
}
