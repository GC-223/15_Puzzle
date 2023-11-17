//
//  Board.hpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/9/23.
//

#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include "Tile.hpp"
#include "PointStruct.hpp"


// board class
class Board
{
private:
    
    // integer for num rows and num cols
    // since it is a 4 x 4 board then they can be same num
    // this will never change thus make it static constexpr
        // maybe in future we can make it so user can change boardSize?
    static constexpr int SIZE { 4 } ;
    
    // thought about using dynamic 2d array for practice
    // that just makes thing unneccessarily hard, especially for a simple project like this
    Tile m_board[ SIZE ] [ SIZE ] ;
    
    
    
public:
    
    // constructor
    // when we create a new board, we want it to be solved at the beginning
    // then we can let the user shuffle it themselves
    // or they can press a shuffle button to shuffle it
    Board ()
    {
        // start tile is 1
        int tileNum { 1 } ;
        
        // now lets initialize our board into the solved state
        for ( int row = 0 ; row < SIZE ; ++row )
        {
            for ( int col = 0 ; col < SIZE ; ++col )
            {
                if ( tileNum < 16 )
                {
                    // number from 1 - 15
                    m_board [ row ] [ col ] = Tile{ tileNum++ } ;
                }
                else
                {
                    // last tile is 'blank' tile (0)
                    tileNum = 0 ;
                    m_board [ row ] [ col ] = Tile{ tileNum } ;
                }
            }
        }
    }
    
    // ok so now we want the function to print the board
    // i guess we want to overload the output operator
    friend std::ostream& operator<<( std::ostream& out, const Board& b ) ;
    
    
    // ok so we finally have everything we need to be able to move a tile on the board
    // to move a tile
    // first locate the blank tile
    
    // separate function to get blank tile coordinates
    Point getBlankCoords()
    {
        // loop through the entire board
        
        // loop through rows (y) coord
        for ( int y = 0 ; y < SIZE ; ++y )
        {
            // cols (x) coord
            for ( int x = 0 ; x < SIZE ; ++x )
            {
                if ( m_board[y][x].isEmpty() )
                {
                    // coords of blank tile
                    return Point { x, y } ;
                }
            }
        }
        // blank tile not found
        return Point { -1, -1 } ;
    }
    
        // get coordinates of blank tile
    
    

    
    // do error handling with valid/invalid inputs
    // return true if valid point
    bool validPoint( Point p )
    {
        return ( p.m_x >= 0 && p.m_x < SIZE ) && ( p.m_y >= 0 && p.m_y < SIZE ) ;
    }
    
    // swap the tiles
    void swap( Point blankPoint, Point adjacentPoint )
    {
        Tile tempTile { m_board[ blankPoint.m_y ][ blankPoint.m_x ] } ;
        
        m_board[ blankPoint.m_y ][ blankPoint.m_x ] = m_board[ adjacentPoint.m_y ][ adjacentPoint.m_x ] ;
        
        m_board[ adjacentPoint.m_y ][ adjacentPoint.m_x ] = tempTile ;
    }
    
    bool moveTile( Direction moveDirection )
    {
        // coords of blankTile
        Point blankPoint { getBlankCoords() } ;
        
        // now find the coordinates of the tile that is adjacent to (opposite input direction) of blank tile
        Point adjacentPoint { blankPoint.getAdjacentPoint( -moveDirection ) } ;
        
        if ( !validPoint( adjacentPoint ) )
        {
            return false ;
        }
        
        swap( blankPoint, adjacentPoint ) ;
        
        return true ;
        
    }
    
} ;

#endif /* Board_hpp */
