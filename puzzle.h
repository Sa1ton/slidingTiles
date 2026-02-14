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
    void setCost(int) ;
    void setParent(Puzzle*); 
    void printParents(); 
    void printParents(Puzzle* p); 
    int getHeuristic(); 
    int calcMisplaced(); 
    void setHeuristic(int); 
    int calcManhattanDistance(); 

private:
    int array[3][3]; 
    int cost=0; 
    Pos zeroIndex; 
    Puzzle* parent=nullptr; 
    int heuristic=0; //set to 0 foe uniformed cost search
};
//functional object to compare so search functions know what to prioritize in priority queues queues
//We add the cost and the heuristic, whichever has the 
struct comparePuzzle{
    bool operator()(Puzzle* P1, Puzzle* P2){
        return P1->getCost() +P1->getHeuristic()> P2->getCost()+P2->getHeuristic();
    }
}; 
#endif