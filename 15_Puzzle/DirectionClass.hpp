//
//  DirectionClass.hpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/12/23.
//

#ifndef DirectionClass_hpp
#define DirectionClass_hpp

#include <iostream>

// lets implement a class that handles the character inputs from the user as directions
class Direction
{
public:
    // so we want to be able to represent 4 main directions
    // up, down, left, right
    // an enum would be good for this
    enum DirectionType
    {
        up,
        down,
        left,
        right,
        
        max_directions,
    } ;
    
    // constructor
    Direction( DirectionType type ) : m_direction { type } { }
    
    // getter
    DirectionType getDirectionType() const
    {
        return m_direction ;
    }
    
    // overload unary operator- to return the opposite direction
    Direction operator-() const ;
    
    // lets overload the output operator so we can print direction
    friend std::ostream& operator<<( std::ostream& out, const Direction& d ) ;
    
    
private:
    
    // member to hold the direction
    DirectionType m_direction { } ;
    
} ;

#endif /* DirectionClass_hpp */
