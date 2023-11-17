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
#include "PointStruct.hpp"
#include "Tile.hpp"
#include "UserInput.hpp"



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

        if ( gameBoard.moveTile( inputDirection ) )
        {
            std::cout << gameBoard << '\n' ;
        }
    }
    
    
    
    
    return 0;
}
