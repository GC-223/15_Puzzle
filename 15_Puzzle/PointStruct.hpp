//
//  PointStruct.hpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/16/23.
//

#ifndef PointStruct_hpp
#define PointStruct_hpp

#include <iostream>
#include "DirectionClass.hpp"

// ok so now we want a class to treat cells on the board as coordinates
// because we want to be able to access these coords it should probably be a struct
struct Point
{
    int m_x ;
    int m_y ;
    
    
    // lets also have a function that gets the point next to a certain point
    // based on a direction
    Point getAdjacentPoint ( Direction d ) ;
    
    // lets overload equality operators to compare two points
    friend bool operator==( const Point& p1, const Point& p2 )
    {
        return ( p1.m_x == p2.m_x ) && ( p1.m_y == p2.m_y ) ;
    }
    
    friend bool operator!=( const Point& p1, const Point& p2 )
    {
        return !( p1 == p2 ) ;
    }

} ;
#endif /* PointStruct_hpp */
