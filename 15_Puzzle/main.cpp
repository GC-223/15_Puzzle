//
//  main.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/8/23.
//

#include <cassert>
#include <iostream>
#include "Board.hpp"
#include "DirectionClass.hpp"
#include "Tile.hpp"

// ok so now we want a class to treat cells on the board as coordinates
// because we want to be able to access these coords it should probably be a struct
struct Point
{
    int m_x ;
    int m_y ;
    
    
    // lets also have a function that gets the point next to a certain point
    // based on a direction
    Point getAdjacentPoint ( Direction d )
    {
        switch (d.getDirectionType()) {
            case Direction::up:
                return Point { m_x, --m_y } ;
            case Direction::down:
                return Point { m_x, ++m_y } ;
            case Direction::left:
                return Point { --m_x, m_y } ;
            case Direction::right:
                return Point { ++m_x, m_y } ;
            default:
                std::cout << "Invalid Direction Entered\n" ;
                return Point { m_x, m_y } ;
        }
        
    }
    
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


// lets use a namespace to handle user input
namespace UserInput
{

    // userInput should be w, a, s, d, or q

    // make sure userInput is valid
    bool validInput ( char input )
    {
        return input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'q' ;
    }


    // we want to be able to get userInput
    char getUserInput()
    {
        char userInput { } ;
        
        // loop until user enters a valid input
        while (!validInput( userInput ) )
        {
            // get user input
            std::cin >> userInput ;
            
            // if std::cin fails for whatever reason
            // handle that
            if ( !std::cin )
            {
                std::cin.clear() ;
            }
            
            std::cin.ignore( 2500, '\n' ) ;
        }
        
        return userInput ;
    }


    // we want a function that will be able to convert a userInput into a direction
    Direction convertToDirection( char userInput )
    {
        switch ( userInput ) {
            case 'w':
                return Direction { Direction::up } ;
            case 'a':
                return Direction { Direction::left } ;
            case 's':
                return Direction { Direction::down } ;
            case 'd':
                return Direction { Direction::right } ;
            default:
                std::cout << "Invalid Input Entered" ;
                return Direction { Direction::up } ;
        }
    }
    
}




int main(int argc, const char * argv[]) 
{
    // testing tile
    Tile t1 { 5 } ;
    Tile t2 { 12 } ;
    Tile t3 { 0 } ;
    Tile t4 { 1 } ;
    
    // testing printing tiles
    std::cout << t1 << t2 << t3 << t4 << '\n' ;
    
    // testing gameboard, and see if it prints correctly
    Board gameBoard { } ;
    std::cout << gameBoard << '\n' ;
    
    // testing if userInput works correctly
    while ( true )
    {
        char input { UserInput::getUserInput() } ;
        
        
        if ( input == 'q' )
        {
            std::cout << "Goodbye!\n" ;
            break ;
        }
        
        Direction inputDirection { UserInput::convertToDirection( input ) } ;

        std::cout << "You entered direction: " << inputDirection << '\n' ;
    }
    
    
    
    
    return 0;
}
