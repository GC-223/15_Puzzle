//
//  main.cpp
//  15_Puzzle
//
//  Created by Greyson Chavez on 11/8/23.
//

#include <iostream>
#include "Board.hpp"
#include "Tile.hpp"



int main(int argc, const char * argv[]) 
{
    
    Tile t1 { 5 } ;
    Tile t2 { 12 } ;
    Tile t3 { 0 } ;
    Tile t4 { 1 } ;
    
    std::cout << t1 << t2 << t3 << t4 << '\n' ;
    
    Board gameBoard { } ;
    
    std::cout << gameBoard << '\n' ;
    
    return 0;
}
