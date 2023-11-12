//
//  main.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/8/23.
//

#include <iostream>
#include "Board.hpp"
#include "Tile.hpp"


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
        
        std::cout << "Valid Command: " << input << '\n' ;
    }
    
    return 0;
}
