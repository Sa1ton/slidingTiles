#ifndef PUZZLE_H  
#define PUZZLE_H

#include <string>
#include <vector>
using namespace std; 
struct Pos{
    int row; 
    int col; 
}; 

class Puzzle {
public:
    Puzzle(); 
    Puzzle(std::string, std::string, std::string); 
    bool isValid(); 
    bool isGoal() const; 
    void print(); 
    bool operator==(const Puzzle& other)const; 
    Puzzle& operator=(const Puzzle& other); 
    void find0(); 
    Pos getzeroIndex();
    vector<Puzzle> expand(); 
    string toString(); 
    int getCost(); 
    void setParent(Puzzle*); 
    void printParents(); 
    void printParents(Puzzle* p); 

private:
    int array[3][3]; 
    int cost=0; 
    Pos zeroIndex; 
    Puzzle* parent=nullptr; 
};
//compare so search functions know what to prioritize in queues
struct comparePuzzle{
    bool operator()(Puzzle* P1, Puzzle* P2){
        return P1->getCost() > P2->getCost();
    }
}; 
#endif