#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "puzzle.h"
using namespace std; 

//default puzzle case; 
Puzzle::Puzzle(){
    array[0][0]=1; 
    array[0][1]=2; 
    array[0][2]=3; 
    array[1][0]=5; 
    array[1][1]=0; 
    array[1][2]=6; 
    array[2][0]=4; 
    array[2][1]=7; 
    array[2][2]=8; 
}
Puzzle::Puzzle(string row1, string row2, string row3){
    stringstream r1(row1); 
    int r1c1, r1c2,r1c3;
    r1>>r1c1>>r1c2>>r1c3;  
    stringstream r2(row2); 
    int r2c1, r2c2,r2c3;
    r2>>r2c1>>r2c2>>r2c3;
    stringstream r3(row3); 
    int r3c1, r3c2,r3c3;
    r3>>r3c1>>r3c2>>r3c3;
    array[0][0]=r1c1; 
    array[0][1]=r1c2; 
    array[0][2]=r1c3; 
    array[1][0]=r2c1; 
    array[1][1]=r2c2; 
    array[1][2]=r2c3;  
    array[2][0]=r3c1; 
    array[2][1]=r3c2; 
    array[2][2]=r3c3; 
}
//checks if the user's puzzle is valid, 
//if nine is entered or repeat number, return false
bool Puzzle::isValid(){ 
    vector<bool> seen(9, false); 
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(array[i][j]>=9|| array[i][j]<0){ 
                return false; 
            }
            if (seen.at(array[i][j])==false){
                seen.at(array[i][j])=true; 
            }
            else if(seen.at(array[i][j])==true){
                return false; 
            }
            
        }
    }
    return true; 
}

bool Puzzle::isGoal(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==2&&j==2){
                if(array[i][j]!=0){
                    return false; 
                } 
            }
            else if(array[i][j]!=(i*3)+j+1){
                return false; 
            }
        }
    }
    return true; 
}

void Puzzle::print(){
    for(int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<array[i][j]<<' '; 
        }
        cout<<"\n"; 
    }
}