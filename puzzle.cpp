#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "puzzle.h"
using namespace std; 

//default puzzle case made random
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
    parent=nullptr; 
    cost=0; 
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
    parent=nullptr; 
    cost=0; 
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

bool Puzzle::isGoal() const{
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
    cout<<"Where g(n) is "<<getCost()<<" and h(n) is "<<getHeuristic()<<"\n"; 
    return; 
}
void Puzzle:: printParents(){
    printParents(this); 
}
void Puzzle:: printParents(Puzzle* p){
    if(p==nullptr){
        return; 
    } 
    printParents(p->parent); 
    p->print(); 
}
//basic compare 
bool Puzzle::operator==(const Puzzle& other) const{
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(array[i][j] != other.array[i][j]) return false; 
        }
    }
    return true; 
}

Puzzle& Puzzle:: operator=(const Puzzle& other){
    if(this!= &other){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                array[i][j]=other.array[i][j]; 
            }
        }
        zeroIndex=other.zeroIndex; 
    }
    return *this; 

}
//find the zero and store it 
void Puzzle:: find0(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if(array[i][j]==0){
                Pos p; 
                p.row=i; 
                p.col=j; 
                zeroIndex=p; 
                return; 
            }
        }
    }
}

Pos Puzzle:: getzeroIndex(){
    return zeroIndex; 
}

//create a vector of possible puzzle states
vector<Puzzle> Puzzle::expand(){
    find0();
    vector<Puzzle> childrens; 
    //swap left
    if (zeroIndex.col>0){
        Puzzle child= *this; 
        child.array[zeroIndex.row][zeroIndex.col]=child.array[zeroIndex.row][zeroIndex.col-1];
        child.array[zeroIndex.row][zeroIndex.col-1]=0; 
        child.cost=this->cost+1;         childrens.push_back(child); 
    }
    //swap right
    if(zeroIndex.col<2){
        Puzzle child=*this; 
        child.array[zeroIndex.row][zeroIndex.col]=child.array[zeroIndex.row][zeroIndex.col+1]; 
        child.array[zeroIndex.row][zeroIndex.col+1]=0;
        child.cost=this->cost+1;          childrens.push_back(child); 
    }
    //swap up
    if(zeroIndex.row>0){
        Puzzle child =*this; 
        child.array[zeroIndex.row][zeroIndex.col]=child.array[zeroIndex.row-1][zeroIndex.col]; 
        child.array[zeroIndex.row-1][zeroIndex.col]=0; 
        child.cost=this->cost+1;
        childrens.push_back(child); 
    }
    //swap down
    if(zeroIndex.row<2){
        Puzzle child=*this; 
        child.array[zeroIndex.row][zeroIndex.col]=child.array[zeroIndex.row+1][zeroIndex.col]; 
        child.array[zeroIndex.row+1][zeroIndex.col]=0; 
        child.cost=this->cost+1;
        childrens.push_back(child); 
    }
    return childrens; 
}

string Puzzle::toString(){
    string s; 
    for (int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            s+=to_string(array[i][j]); 
        }
    }
    return s; 
}

int Puzzle::getCost(){
    return cost; 
}

void Puzzle::setParent(Puzzle* p){
    parent=p; 
}

int Puzzle::getHeuristic(){
    return heuristic; 
}

int Puzzle::calcMisplaced(){
    int counter=0; 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(array[i][j]!=(i*3)+j+1&& array[i][j]!=0){
                counter++; 
            }
        }
    }
    return counter; 
}

void Puzzle:: setHeuristic(int h){
    heuristic=h; 
}