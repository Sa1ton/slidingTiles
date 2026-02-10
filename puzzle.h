#ifndef PUZZLE_H  
#define PUZZLE_H

#include <string>
#include <vector>

class Puzzle {
public:
    Puzzle(); 
    Puzzle(std::string, std::string, std::string); 
    bool isValid(); 
    bool isGoal(); 
    void print(); 
private:
    int array[3][3]; 
};

#endif