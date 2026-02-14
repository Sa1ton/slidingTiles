#include <queue>
#include <unordered_map>
#include <iostream>
#include "mth.h"
#include "puzzle.h"


//Misplaced Tile Function
Puzzle* mthFunction(Puzzle* p){
    int nodesExpanded=0; 
    int maxQueueSize=0; 
    string key=p->toString(); 
    p->setHeuristic(p->calcMisplaced()); 
    unordered_map<string, int> visited; 
    visited[key]=p->getCost(); 
    priority_queue<Puzzle*, vector<Puzzle*>, comparePuzzle> nodes; 
    nodes.push(p); 
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
            int new_g=node->getCost()+1; 
            for(Puzzle& child:children){
                string childkey=child.toString(); 
                if (visited.find(childkey)== visited.end()||new_g<visited[childkey]){
                    visited[childkey]=new_g; 
                    Puzzle* heapchild= new Puzzle(child); 
                    heapchild->setParent(node);  
                    heapchild->setCost(new_g); 
                    heapchild->setHeuristic(heapchild->calcMisplaced()); 
                    nodes.push(heapchild); 
                }
            }
    }
    return NULL; 
}



