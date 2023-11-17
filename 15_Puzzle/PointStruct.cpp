//
//  PointStruct.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/16/23.
//

#include "PointStruct.hpp"

// lets also have a function that gets the point next to a certain point
// based on a direction
Point Point::getAdjacentPoint ( Direction d )
{
    switch (d.getDirectionType()) {
        case Direction::up:
            return Point { m_x, m_y - 1 } ;
        case Direction::down:
            return Point { m_x, m_y + 1 } ;
        case Direction::left:
            return Point { m_x - 1, m_y } ;
        case Direction::right:
            return Point { m_x + 1, m_y } ;
        default:
            std::cout << "Invalid Direction Entered\n" ;
            return Point { m_x, m_y } ;
    }
    
}
