#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <queue>
#include "puzzle.h"
#include "ucs.h"

using namespace std; 

Puzzle* solution;  
void general_search(Puzzle&, int); 
int main(){
    int input; 
    Puzzle puzzle;
    cout<<"Welcome to my 8-Puzzle Solver. Type '1' to use a default puzzle, or '2' to create your own.\n"; 
    cin>>input; 
    if (input==1){
        puzzle=Puzzle(); 
        puzzle.print(); 
    }
    else if (input == 2){
        string row1, row2, row3; 
        int function; 
        cout<<"Enter your puzzle, using a zero to represent the blank. Please only enter valid 8 - puzzles. Enter the puzzle demilimiting the numbers with a space. Type RETURN only when finished.\n"; 
        cout<<"Enter first row: "; 
        cin.ignore(); 
        getline(cin, row1);  
        cout<<"Enter second row: "; 
        getline(cin,row2); 
        cout<<"Enter third row: "; 
        getline(cin,row3);  
        puzzle=Puzzle(row1,row2,row3); 
        cout<<"Select algorithm. (1) for Uniform Cost Search, (2) for the Misplaced Tile Heuristic, or (3) the Manhattan Distance Heuristic.\n"; 
        cin>>function;
        general_search(puzzle, function); 
        if(solution!=nullptr){
            solution->printParents(); 
        }   
        else{
            cout << "\nNo solution was found. Check if the puzzle is solvable.\n";
        }
        
    }
    return 0; 
}

void general_search(Puzzle& p, int function){
     if (function==1){
        solution= ucsFunction(&p); 
        return; 
     }
     else if(function==2){
        return; 
     }
     else if(function ==3){
        return; 
     }
 }