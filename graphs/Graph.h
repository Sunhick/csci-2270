//
//  Graph.h
//  zombies
//
//  Created by Sunil on 4/17/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

template <class T>
struct vertex;

template <class T>
struct adjVertex {
    vertex<T>* v;
    int weight;
};

template <class T>
struct vertex {
    int districtId = -1;
    T name;
    std::vector<adjVertex<T>> adj;
};

template <class T>
class Graph {
public:
    Graph();
    ~Graph();
    
    void addEdge(T v1, T v2, int weight);
    void addVertex(T name);
    void displayEdges();
    void displayVertices();
    void assignDistrictIds();
    void findShortestPath(std::string, std::string);
    
private:
    std::vector<vertex<T>> vertices;
    
    void bfsAssignId(vertex<T>&, int);
};

#include "Graph.cpp"

#endif // GRAPH_H
