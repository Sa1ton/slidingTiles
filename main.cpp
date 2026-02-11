#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include "ucs.cpp"
#include "puzzle.h"

using namespace std; 
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
        cout<<"Enter your puzzle, using a zero to represent the blank. Please only enter valid 8 - puzzles. Enter the puzzle demilimiting the numbers with a space. Type RETURN only when finished.\n"; 
        cout<<"Enter first row: "; 
        cin.ignore(); 
        getline(cin, row1);  
        cout<<"Enter second row: "; 
        getline(cin,row2); 
        cout<<"Enter third row: "; 
        getline(cin,row3);  
        puzzle=Puzzle(row1,row2,row3); 
        //puzzle.print(); 
    }
    return 0; 
}

// bool general_search(Puzzle,string function){
//     vector<Puzzle>
// }