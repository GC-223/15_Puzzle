//
//  DirectionClass.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/12/23.
//

#include "DirectionClass.hpp"

// overload unary operator- to return the opposite direction
Direction Direction::operator-() const
{
    switch (m_direction) {
        case up:
            return Direction{ down } ;
        case down:
            return Direction{ up } ;
        case left:
            return Direction { right } ;
        case right:
            return Direction { left } ;
        default:
            std::cout << "Invalid Direction Entered\n" ;
            return Direction { up } ;
    }
}


// lets overload the output operator so we can print direction
std::ostream& operator<<( std::ostream& out, const Direction& d )
{
    switch (d.m_direction) {
        case Direction::up:
            out << "up" ;
            break ;
        case Direction::down:
            out << "down" ;
            break ;
        case Direction::left:
            out << "left" ;
            break ;
        case Direction::right:
            out << "right" ;
            break ;
        default:
            out << "Invalid Direction Entered\n" ;
            break;
    }
    
    return out ;
}
