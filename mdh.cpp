#include <queue>
#include <unordered_set>
#include <iostream>
#include <cmath>
#include "mdh.h"
#include "puzzle.h"

//initial setup 
Puzzle* mdhFunction(Puzzle* p){
    int nodesExpanded=0; 
    int maxQueueSize=0; 
    p->setHeuristic(p->calcManhattanDistance()); 
    unordered_set<string> visited; 
    priority_queue<Puzzle*, vector<Puzzle*>, comparePuzzle> nodes; 
    nodes.push(p); 
    visited.insert(p->toString());
    while(!nodes.empty()){
        if(nodes.size()>maxQueueSize){
            maxQueueSize=nodes.size(); 
        }
        Puzzle* node=nodes.top(); 
        nodes.pop(); 
        nodesExpanded++; 
        // debugger
        // cout << "Expanding state: " << node->toString() << " | Queue size: " << nodes.size() << endl;
        if(node->isGoal()){
            cout << "\nGoal State!\n\n";
            cout<<"Solution Depth was "<<node->getCost(); 
            cout<<"\nNumber of nodes expanded: "<<nodesExpanded; 
            cout<<"\nMax queue size: "<< maxQueueSize<<"\n"; 
            return node; 
        } 
            vector<Puzzle> children=node->expand(); 
            for(Puzzle& child:children){
                if (visited.find(child.toString())== visited.end()){
                    visited.insert(child.toString());
                    Puzzle* heapchild= new Puzzle(child); 
                    heapchild->setParent(node);  
                    heapchild->setHeuristic(heapchild->calcManhattanDistance()); 
                    nodes.push(heapchild); 
                }
            }
    }
    return NULL; 
}



